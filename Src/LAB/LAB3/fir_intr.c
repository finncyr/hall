// fir_intr.c 
#include "LabCode.h"

#ifdef LAB3_FIR_INTR
#include "LAB/Module_6/bp1750.h"

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;

float32_t x[N];
int16_t k = 0;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{            
  float32_t yn = 0.0;
  int i;
    
  audio_chL = inLeft;
  audio_chR = inRight;

  x[k++] = (float32_t)(audio_chL);
  if (k >= N) k = 0;
  for (i=0 ; i<N ; i++)
  {
	yn += h[i]*x[k++];
	if (k >= N) k = 0;
  }
  audio_chL = (int32_t)(yn);

  *outLeft = audio_chL;
  *outRight = audio_chR;
}
 
void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif