# Final Report 

## Task
Goal of this project was to build an audio effect device based on the  STM32F796I-DISCO development platform. The desired audio effect was a reverb. In order to realize this idea the following requirements had to be met (all non bold requirements are considered optional):

1. __reading samples from the onboard audio codec__
2. __processing the read samples__
3. __outputting the processed samples via the onboard audio codec__
4. handling user IO via the included touchscreen

### 1. Audio Input
The audio input should handle fetching samples from the onboard audio codec using the HAL. Due to performance constraints, it should do so while ensuring minimal CPU usage.

### 2. Audio processing
Audio processing should create a reverb effect using DSP audio filters. If possible, a schroeder reverb filter setup should be used. For further information on a schroeder reverb please consult this [paper][Schröder reverb paper]. Should time or CPU constraints not allow this implementaion, a FIR filter setup using the impluse response of a reverberating room can be used instead. 

### 3. Audio output
The audio output should handle outputting samples to the onboard audio codec using the HAL. Due to performance constraints, it should do so while ensuring minimal CPU usage. Additionally possiblie clipping caused by the audio processing should be prevented before outputting.

### 4. User IO
The user IO should allow the user to enable and disable the reverb effect. Should multiple reverb effects be implemented, the user should be able to enable/disable them individually and combine them. Ideally this IO is to be implemented using the Touchscreen of the STM32F769I. Should time or CPU constraints not allow this implementation, IO is to be handled using the user button of the board.


The following chapters shall desrcibe how these requirements were met by first discussig the hardware used in the project. Subsequently the process of developing the software will be described. The final state of the software will be explained in the final chapter, after which a summary will sum up the results of the project. 

---

## Table of contents

  * [Task](#task)
    + [1. Audio Input](#1-audio-input)
    + [2. Audio processing](#2-audio-processing)
    + [3. Audio output](#3-audio-output)
  * [Table of contents](#table-of-contents)
  * [Hardware](#hardware)
  * [Software](#software)
    + [Development](#development)
    + [Final results](#final-results)
    + [User Interface](#user-interface)
  * [Summary](#summary)
  * [Appendix](#appendix)
  * [Quotations](#quotations)


---

## Hardware
The audio effect device is based on the *STM32 F769I-Disco* development platform. It consists of a STM32F769NIH6 microcontroller and supplementary hardware. A capacative touchscreen can be attached to the board using a DSI connector. Audio IO is handled via a SAI audio codec. 

---

## Software
Due to growing experience with the hardware and its capabilities and especially its limitations, the architecture of the software has changed a lot during development. This chapter will first discuss the development of the software, and why changes were necessary. 

### Development
The early versions of the software were based on interrupt based audio processing. This meant the software would send an interrupt to the processor every time a sample was available. The processor would then execute an ISR called ```Sample_Callback()```. In this function, the sample would then be placed in a circulary buffer. The buffer was then used to feed the audio filters. The current output sample of the filters would then be written to the audio output. However, this architecture prooved to be problematic in multiple ways. 

First of all,  in order to achieve an acceptable audio quality the sampling rate of the codec was set to 48 kHz. This meant that each call of the ISR only had a theorecical maximum of 21 microseconds to finish its computations, which prooved to be unsuficcient to rum the filters. On top of that in practise the save and load operations performed to handle each interrupt further diminished the theoretical time for each callback. 

In order to lower the amount of interrupts and filter executions, the software architecture was changed to a DMA based approach. This meant the audio codec would write a block of samples into memory before calling the ISR. The ISR, now called ```ProcessBuffer()```, would then process the entire block of samples and output it. In order to ensure a static block of samples during processing, the audio codec would alternate between a so called ping and pong buffer on both the in- and outputs. Each of the alternating callbacks required to realize this structure are called half callbacks. 

This did save a lot of CPU usage. However, the original plan of using 4 parallel combfilters and 2 serial allpass filters afterwards to realiza a schroeder reverb were still too CPU intensive. This resulted in very loud repeating chirping noises at the output.

In order to address this the filter was scaled back to a simple FIR using a optimised filter function [provided by ARM for their processors][arm_fir_f32]. However, even this was not enough to resolve the performance issues. The block size was increased from its default value and the impulse response had to be shortened.



### Final results
Consequently, the software in its final form is a DMA based approach. The IO is handled though a ping pong buffer configuration. It uses a FIR filter for processing and is optimised for the processors capabilities. The used filter function stores its state between calls, so no overlap and add routine had to be implemented to handle a continuous effect when switching between buffers. The maximum impulse response length at 48 kHz and a blocksize of 512 turned out to be 512 samples (about 11 microseconds). 

The following code snippet will help illustrate the inner workings of our signal processing:
```c

void ProcessBuffer()
{
	//seperate samples
	seperated_buf_index = 0;
	for (int n = 0; n < BUFFER_SIZE; n+=2)
	 {
		audio_chL[seperated_buf_index]= ProcessingBuffer.Input[n];
	    audio_chR[seperated_buf_index]= ProcessingBuffer.Input[n+1];
	    seperated_buf_index ++;
	 }

    //cast input to float
	for(int i = 0; i<BUFFER_SIZE/2;i++){
		audio_chL_f[i] = (float32_t)audio_chL[i];
	}

    //initialise filter
	arm_fir_instance_f32 S = {numTaps, pState, h};
    //filter input
	arm_fir_f32 (&S, audio_chL_f, conv_resL,BUFFER_SIZE/2);


	//reassemble buffer
	 seperated_buf_index = 0;
	 for (int n = 0; n < BUFFER_SIZE; n+=2)
	 {
		 ProcessingBuffer.Output[n] = (int32_t) (0.28*conv_resL[seperated_buf_index]);
		 ProcessingBuffer.Output[n+1] = audio_chR[seperated_buf_index];
		 seperated_buf_index ++;
	 }
}


```
The process buffer fuction is called everytime one of the input buffers finished being filled. As left and right channel samples are stored in an alternating pattern in the buffer they forst have to be seperated in the first for loop. The second for loop then casts the samples to float32_t in order to make them compatible with the filter function. The filter is then initialised using the length of the audio channel buffers (numTaps), the state of the last filter execution (pState, global variable) and the filter impulse response (h, stored in the filter header file). After initialisation, the filter is then applied to the left audio channel. The right channel is untouched in order to provide a comparison signal. After processing, the audio channel samples are written alternating to the output buffer. 

### User Interface

Our user interface is currently based on the Touch-Panel of the STM32. We implemented a simple LCD routine which draws a round button in the middle of the screen which can be activated by pressing it. If the button is pressed, the color shifts to green instead of the standarized gray.
The detection of the touch input gets stored in a flip-flop variable which is available globally. To use this variable in our Audio ISR we had to map the Variable ```copy_tsIsPressed``` onto the adress of the global variable. 

We already detected a problem with the system: multiple touch recognition.
If you leave your finger pressed on the touch screen and move it a few pixels on the screen, the software detects these movements as new touch inputs and activates the button again. The solution would be a "difference function" which checks if the newly detected input is really a new touch input or just a movement of the existing input by a few pixels. We might not be able to implement this function by the deadline of our project, because we focus on readability and proper comments right now.

---

## Summary

In summary, the project was scaled down a lot during development due to performance constraints of the CPU. The final software is a DMA based FIR filter system.  
<!-- todo:user IO
-->
---

## Appendix
- __List of abbreviations__
  - FIR - finite  impulse response
  - DMA - direct memory access
  - ISR - interrupt service routine
  - CPU - central processing unit
  - codec - encoder/decoder unit
  - SAI - serial audio interface
  - DSI - display serial interface
---

## Quotations
[paper on schroeder reverb][Schröder reverb paper]

[inspiration for schroeder reverb implementation][java reverb tutorial]

[source of the used impulse responses][echothief]

[filterfunction documentation][arm_fir_f32]

[other filterfunctions considered during development][CMSIS DSP]







[Schröder reverb paper]: https://pdfs.semanticscholar.org/48a5/32a015e3cbb863e28b6cca8ad4ca849065b7.pdf
[java reverb tutorial]: https://medium.com/the-seekers-project/coding-a-basic-reverb-algorithm-part-2-an-introduction-to-audio-programming-4db79dd4e325
[echothief]:http://www.echothief.com/
[toc]:https://ecotrust-canada.github.io/markdown-toc/
[CMSIS DSP]: https://www.keil.com/pack/doc/CMSIS/DSP/html/index.html
[arm_fir_f32]:https://www.keil.com/pack/doc/CMSIS/DSP/html/group__FIR.html#ga0cf008f650a75f5e2cf82d10691b64d9