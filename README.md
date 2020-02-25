# hall
------
*please note:*

*all documentation relevant for grading this project can be found in finalReport.docx*

*the .elf file which we use can be found under [this link](https://github.com/finncyr/hall/releases/tag/1.1)*

------
*Project for SMMD in WS 19/20*
*Participants: Finn Cyriax, Manuel Faatz*

![](https://img.shields.io/github/contributors/finncyr/hall?color=blue)
![](https://img.shields.io/github/license/finncyr/hall)
![](https://img.shields.io/github/last-commit/finncyr/hall)

## Description of Project

This project is aimed at creating a device that can alter an audio signal provided by a microphone using an reverb effect. Should the team have the time, additional effects will be implemented. 
The project will be implemented using the STM32 development platform provided by our professors. The audio signal will be obtained from the microphone using the audio codec integrated into the development board. The audio data will be transported from the codec to the SoC using DMA in a ping/pong configuration.
In order to enable using the last few bits of the ping buffer as inputs for the pong buffer processing (and vice versa), they will have to be copied to the beginning of the pong buffer (and vice versa).
The audio signal will then be processed by the SoC using FIR/IIR filters to realize the desired audio effects.

After processing the audio signal is returned to the CODEC using DMA in ping/pong configuration as well. The overlap creating by copying the end of one input buffer to the beginning of the next will have to be accounted for. 
Since user IO is not time sensitive it will not be handled when the CPU has cycles to spare. This will be used by handling IO in the main loop, since it only executes when there are no ISRs running. To save more cycles a simple polling could be implemented that prevents the IO functions from executing too often when the CPU is not handling interrupts. 

## Goals

The final project software should contain the following features:

- IO to change effects whilst running
- Various Effects:
  - Echo
  - Delay
  - Reverb
- Mute Button
- Audio Passthrough

The application should be executable as a stand-alone solution for the STM32 Dev Kit.

*Last Updated: 07.01.2020*
