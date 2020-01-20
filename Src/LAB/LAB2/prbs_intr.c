// prbs_intr.c 
#include "LabCode.h"

#ifdef LAB2_PRBS_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  audio_chL = inLeft;
  audio_chR = inRight;

  audio_chL = prbs()<<16;
  audio_chR = audio_chL;
  	
  *outLeft = audio_chL;
  *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif