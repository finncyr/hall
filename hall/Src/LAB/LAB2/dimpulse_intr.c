// dimpulse_intr.c 
#include "LabCode.h"

#ifdef LAB2_DIMPULSE_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define LOOP_SIZE 64
int16_t impulse_table[LOOP_SIZE] = {
10000, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0};
static int impulse_ptr = 0;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  audio_chL = inLeft;
  audio_chR = inRight;

  audio_chL = impulse_table[impulse_ptr]<<16;
  audio_chR = impulse_table[impulse_ptr]<<16;
  impulse_ptr = (impulse_ptr+1) % LOOP_SIZE;
	
  *outLeft = audio_chL;
  *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
