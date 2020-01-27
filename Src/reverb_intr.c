// reverb_intr.c
#include "LabCode.h"

#ifdef LAB1_REVERB_INTR


volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;

void combFilter(uint32_t *samples, uint32_t *output, int samplesLength, int delayInMilliSec, int decayFactor, int sampleRate);
void allPassFilter(uint32_t *samples, uint32_t *output, int samplesLength, int sampleRate);

int32_t i = 0;

void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight,
	bool activateReverb,
	bool activateDelay
)
{	   	
  audio_chL = inLeft;      
  audio_chR = inRight;
  
  // BOB! DO SOMETHING!
  if(activateDelay){
	  //use combFilter as delay
	  allPassFilter(&audio_chL, &audio_chL, samplesLength, Fs, decayFactor);
	  allPassFilter(&audio_chR, &audio_chR, samplesLength, Fs, decayFactor);
  }


  if(activateReverb){
	  uint32_t inLeft_Comb0, inLeft_Comb1,inLeft_Comb2,inLeft_Comb3;
	  uint32_t inRight_Comb0,inRight_Comb1,inRight_Comb2,inRight_Comb3;
	  uint32_t inLeft_Comb;
	  uint32_t inRight_Comb;

	  //parallel comb filters left channel
	  combFilter(&audio_chL, &inLeft_Comb0, samplesLength, comb0_delay_time, comb0_loop_gain, Fs);
	  combFilter(&audio_chL, &inLeft_Comb1, samplesLength, comb1_delay_time, comb1loop_gain, Fs);
	  combFilter(&audio_chL, &inLeft_Comb2, samplesLength, comb2_delay_time, comb2_loop_gain, Fs);
	  combFilter(&audio_chL, &inLeft_Comb3, samplesLength, comb3_delay_time, comb3_loop_gain, Fs);

	  //parallel comb filters right channel
	  combFilter(&audio_chR, &inRight_Comb0, samplesLength, comb0_delay_time, comb0_loop_gain, Fs);
	  combFilter(&audio_chR, &inRight_Comb1, samplesLength, comb1_delay_time, comb1_loop_gain, Fs);
	  combFilter(&audio_chR, &inRight_Comb2, samplesLength, comb2_delay_time, comb2_loop_gain, Fs);
	  combFilter(&audio_chR, &inRight_Comb3, samplesLength, comb3_delay_time, comb3_loop_gain, Fs);

	  //todo sum up comb filter signals and limit them

	  //Serial allpass filters left
	  allPassFilter(&audio_chL_Comb, &audio_chL_Comb, samplesLength, Fs, decayFactor);
	  allPassFilter(&audio_chL_Comb, &audio_chL_Comb, samplesLength, Fs, decayFactor);

	  //Serial allpass filters right
	  allPassFilter(&audio_chR_Comb, &audio_chR_Comb, samplesLength, Fs, decayFactor);
	  allPassFilter(&audio_chR_Comb, &audio_chR_Comb, samplesLength, Fs, decayFactor);
  }

  
  *outLeft = audio_chR;     
  *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz48000, line_in, 
        Sample_Callback);
}

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

	///TODO: Anti-Clipping & Smoothing out Samples
	//
	///
	
}

#endif


/** 
 *  DEMO CODE GRABBED FROM AN JAVA PROJECT
 * 
//Method for Comb Filter
	public float[] combFilter(float[] samples, int samplesLength, float delayinMilliSeconds, float decayFactor, float sampleRate)
	{
		//Calculating delay in samples from the delay in Milliseconds. Calculated from number of samples per millisecond
		int delaySamples = (int) ((float)delayinMilliSeconds * (sampleRate/1000));
		
		float[] combFilterSamples = Arrays.copyOf(samples, samplesLength);
	
		//Applying algorithm for Comb Filter
		for (int i=0; i<samplesLength - delaySamples; i++)
		{
			combFilterSamples[i+delaySamples] += ((float)combFilterSamples[i] * decayFactor);
		}
	return combFilterSamples;
	}
	
	//Method for All Pass Filter
	public float[] allPassFilter(float[] samples, int samplesLength, float sampleRate)
	{
		int delaySamples = (int) ((float)89.27f * (sampleRate/1000)); // Number of delay samples. Calculated from number of samples per millisecond
		float[] allPassFilterSamples = new float[samplesLength];
		float decayFactor = 0.131f;

		//Applying algorithm for All Pass Filter
		for(int i=0; i<samplesLength; i++)
			{
			allPassFilterSamples[i] = samples[i];
		
			if(i - delaySamples >= 0)
				allPassFilterSamples[i] += -decayFactor * allPassFilterSamples[i-delaySamples];
		
			if(i - delaySamples >= 1)
				allPassFilterSamples[i] += decayFactor * allPassFilterSamples[i+20-delaySamples];
			}
		
	
		//This is for smoothing out the samples and normalizing the audio. Without implementing this, the samples overflow causing clipping of audio
		float value = allPassFilterSamples[0];
		float max = 0.0f;
		
		for(int i=0; i < samplesLength; i++)
		{
			if(Math.abs(allPassFilterSamples[i]) > max)
				max = Math.abs(allPassFilterSamples[i]);
		}
		
		for(int i=0; i<allPassFilterSamples.length; i++)
		{
			float currentValue = allPassFilterSamples[i];
			value = ((value + (currentValue - value))/max);

			allPassFilterSamples[i] = value;
		}		
	return allPassFilterSamples;
	}
**/
