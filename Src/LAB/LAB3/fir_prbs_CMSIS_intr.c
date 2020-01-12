// fir_prbs_CMSIS_intr.c 
#include "LabCode.h"

#ifdef LAB3_FIR_PRBS_CMSIS_INTR
#include "LAB/Module_6/bp1750.h"

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;  

float32_t x, y, state[N];
arm_fir_instance_f32 S;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{           
  audio_chL = inLeft;
  audio_chR = inRight;

  x = (float32_t)(prbs()<<16);
  arm_fir_f32(&S, &x, &y, 1);
  audio_chL = (int32_t)(y);

  *outLeft = audio_chL;
  *outRight = audio_chR;
}

void Init()
{
  arm_fir_init_f32(&S,N,h,state,1);
  AudioInitIT(hz8000, line_in,
      Sample_Callback);
}

#endif
