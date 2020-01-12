// sine_intr.c 
#include "LabCode.h"

#ifdef LAB2_SINE_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define SAMPLING_FREQ 8000
float32_t frequency = 1000.0;
float32_t amplitude = 2000.0*(1<<16);
float32_t theta_increment;
float32_t theta = 0.0f;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  audio_chL = inLeft;
  audio_chR = inRight;

  theta_increment = 2*M_PI*frequency/SAMPLING_FREQ;
  theta += theta_increment;
  if (theta > 2*M_PI) {
    theta -= 2*M_PI;
  } 
  audio_chL = (int32_t)(amplitude*sin(theta));
  //audio_chR = audio_chL;
  audio_chR = inRight;
	
  *outLeft = audio_chL;
  *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
