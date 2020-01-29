#include "LabCode.h"
#include "Audio/audio.h"
#include "FFT/fft.h"
#include "STM32F769I-Discovery/stm32f769i_discovery_lcd.h"
#include "reverb.h"
#include "stdlib.h"

bool data_available = false;
bool processing_data = false;

//todo: acitvation signals need to be set by IO function
bool activateDelay = false;
bool activateReverb = true;

void combFilter(uint32_t *samples, uint32_t *output, int samplesLength, int delayInMilliSec, int decayFactor, int sampleRate);
void allPassFilter(uint32_t *samples, uint32_t *output, int samplesLength, int sampleRate, float32_t decayFactor);



void ProcessBuffer()
{
  int seperated_buf_index = 0;
  uint32_t audio_chL[BUFFER_SIZE/2];
  uint32_t audio_chR[BUFFER_SIZE/2];

  //seperate left and right channel samples from processingBuffer
  for (int n = 0; n < BUFFER_SIZE; n+=2)
  {
    audio_chL[seperated_buf_index]= ProcessingBuffer.Input[n];
    audio_chR[seperated_buf_index]= ProcessingBuffer.Input[n+1];
    seperated_buf_index ++;
  }

  if(activateDelay){
  	  //use combFilter as delay
  	  combFilter(audio_chL, audio_chL, samples_length,delay_delay_time , delay_loop_gain, Fs);
  	  combFilter(audio_chR, audio_chR, samples_length,delay_delay_time , delay_loop_gain, Fs);
    }


    if(activateReverb){
  	  uint32_t inLeft_Comb0 [BUFFER_SIZE/2], inLeft_Comb1 [BUFFER_SIZE/2],inLeft_Comb2 [BUFFER_SIZE/2],inLeft_Comb3 [BUFFER_SIZE/2];
  	  uint32_t inRight_Comb0 [BUFFER_SIZE/2],inRight_Comb1 [BUFFER_SIZE/2],inRight_Comb2 [BUFFER_SIZE/2],inRight_Comb3 [BUFFER_SIZE/2];
  	  uint32_t inLeft_Comb [BUFFER_SIZE/2];
  	  uint32_t inRight_Comb [BUFFER_SIZE/2];

  	  //parallel comb filters left channel
  	  combFilter(audio_chL, inLeft_Comb0, samples_length, comb0_delay_time, comb0_loop_gain, Fs);
  	  combFilter(audio_chL, inLeft_Comb1, samples_length, comb1_delay_time, comb1_loop_gain, Fs);
  	  combFilter(audio_chL, inLeft_Comb2, samples_length, comb2_delay_time, comb2_loop_gain, Fs);
  	  combFilter(audio_chL, inLeft_Comb3, samples_length, comb3_delay_time, comb3_loop_gain, Fs);

  	  //parallel comb filters right channel
  	  combFilter(audio_chR, inRight_Comb0, samples_length, comb0_delay_time, comb0_loop_gain, Fs);
  	  combFilter(audio_chR, inRight_Comb1, samples_length, comb1_delay_time, comb1_loop_gain, Fs);
  	  combFilter(audio_chR, inRight_Comb2, samples_length, comb2_delay_time, comb2_loop_gain, Fs);
  	  combFilter(audio_chR, inRight_Comb3, samples_length, comb3_delay_time, comb3_loop_gain, Fs);

  	  //summing up combfilter signals
  	  for(int i=0; i < seperated_buf_index; i++){
  		  inLeft_Comb[i] = inLeft_Comb0[i] +inLeft_Comb1[i] + inLeft_Comb2[i] + inLeft_Comb3[i];
  		  inRight_Comb[i] = inRight_Comb0[i] +inRight_Comb1[i] + inRight_Comb2[i] + inRight_Comb3[i];
  	  }

  	  //Serial allpass filters left
  	  allPassFilter(inLeft_Comb, inLeft_Comb, samples_length, Fs, allpass0_loop_gain);
  	  allPassFilter(inLeft_Comb, inLeft_Comb, samples_length, Fs, allpass0_loop_gain);

  	  //Serial allpass filters right
  	  allPassFilter(inRight_Comb, inRight_Comb, samples_length, Fs, allpass1_loop_gain);
  	  allPassFilter(inRight_Comb, inRight_Comb, samples_length, Fs, allpass1_loop_gain);
    }

    seperated_buf_index = 0;
    for (int n = 0; n < BUFFER_SIZE; n+=2)
    {
      ProcessingBuffer.Output[n] = audio_chL[seperated_buf_index];
      ProcessingBuffer.Output[n+1] = audio_chR[seperated_buf_index];
      seperated_buf_index ++;
    }

  //Irrelevant
  if (processing_data == false)
  {
    //Copy_To_FFT_Buffer(ProcessingBuffer.Input);
    data_available = true;
  }
  // circularly increment interrupt counter
  if (++interrupt_counter == CM)
  {
    interrupt_counter = 0;
  }
  cycles_btwn_irs[interrupt_counter] = 0;
}

void Init()
{//48kHz -> FS auch aendern
    AudioInitDMA(hz48000, line_in, ProcessBuffer, ProcessBuffer);
}

uint32_t cycles_btwn_irs[CM] = {0};
uint16_t interrupt_counter = 0; //counter for the interrupts


// Submethod for Comb Filter
void combFilter(uint32_t *samples, uint32_t *output, int samplesLength, int delayInMilliSec, int decayFactor, int sampleRate){

    int delayOfSamples = delayInMilliSec * (sampleRate/1000);

	for(int i = 0; i < samplesLength; i++) output[i] = samples[i];

    for (int i = 0; i < samplesLength - delayOfSamples; i++){
        output[i+delayOfSamples] += output[i] * decayFactor;
    }
}

// Submethod for Allpass-Filter
void allPassFilter(uint32_t *samples, uint32_t *output, int samplesLength, int sampleRate, float32_t decayFactor){

	int delaySamples = (int) ((float) 89.27 * (sampleRate / 1000));

	uint32_t allPassFilterSamples[samplesLength];

	for(int i = 0; i < samplesLength; i++){
		allPassFilterSamples[i] = samples[i];

		if(i - delaySamples >= 0){
			allPassFilterSamples[i] += -1*decayFactor * allPassFilterSamples[i-delaySamples];
		}
		if(i - delaySamples >= 1){
			allPassFilterSamples[i] += decayFactor * allPassFilterSamples[i+20-delaySamples];
		}
	}

	//This is for smoothing out the samples and normalizing the audio. Without implementing this, the samples overflow causing clipping of audio
		uint32_t value = allPassFilterSamples[0];
		uint32_t max = 0;

		for(int i=0; i < samplesLength; i++)
		{
			if(abs(allPassFilterSamples[i]) > max)
				max = abs(allPassFilterSamples[i]);
		}

		for(int i=0; i < sizeof(allPassFilterSamples)/sizeof(uint32_t); i++)
		{
			uint32_t currentValue = allPassFilterSamples[i];
			value = ((value + (currentValue - value))/max);

			allPassFilterSamples[i] = value;
		}

}

