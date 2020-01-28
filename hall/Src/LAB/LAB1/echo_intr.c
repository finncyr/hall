// echo_intr.c 
#include "LabCode.h"

#ifdef LAB1_ECHO_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;    

#define DELAY_BUF_SIZE 16000
#define GAIN 0.6f

int32_t buffer[DELAY_BUF_SIZE] = {0};
int32_t buf_ptr = 0;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  int32_t delayed_sample;
  int32_t audio_out_chL = 0;	
    
  audio_chL = inLeft;
  audio_chR = inRight;

  delayed_sample = buffer[buf_ptr];
  audio_out_chL = delayed_sample + audio_chL;
  buffer[buf_ptr] = audio_chL + delayed_sample*GAIN;
  buf_ptr = (buf_ptr+1)%DELAY_BUF_SIZE;
    
  *outLeft = audio_out_chL;
  *outRight = audio_chR;
}

void Init()
{
	AudioInitIT(hz48000, line_in,
		Sample_Callback);
}

#endif
