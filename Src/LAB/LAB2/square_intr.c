// square_intr.c
#include "LabCode.h"

#ifdef LAB2_SQUARE_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define LOOP_SIZE 64
int16_t square_table[LOOP_SIZE] = {
10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000,
10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000,
10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000,
10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000,
-10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
-10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
-10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
-10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000};
static int square_ptr = 0;
 
void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{
  audio_chL = square_table[square_ptr]<<16;
  audio_chR = square_table[square_ptr]<<16;
  square_ptr = (square_ptr+1) % LOOP_SIZE;
	
  *outLeft = audio_chL;
  *outRight = audio_chR;
}

void Init()
{
  AudioInitIT(hz8000, line_in,
      Sample_Callback);
}

#endif
