// average_prbs_intr.c 
#include "LabCode.h"

#ifdef LAB3_AVERAGE_PRBS_INTR
#include "LAB/Module_6/ave5.h"

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;

#define N 5
float32_t h[N];
float32_t x[N];
int16_t k = 0;
int16_t i;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  float32_t yn = 0.0;
    
  audio_chL = inLeft;
  audio_chR = inRight;

  x[k++] = (float32_t)(prbs());
  if (k >= N) k = 0;
  for (i=0 ; i<N ; i++)
  {
    yn += h[i]*x[k++];
    if (k >= N) k = 0;
  }
  audio_chL = (int32_t)(yn);
    
  *outLeft = audio_chL<<16;
  *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
