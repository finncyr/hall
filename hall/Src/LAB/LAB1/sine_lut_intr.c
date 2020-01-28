// sine_lut_intr.c
#include "LabCode.h"

#ifdef LAB1_SINE_LUT_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define LOOP_SIZE 8
int16_t sine_table[LOOP_SIZE] = {0, 7071, 10000, 7071, 0, -7071, -10000, -7071};
static int sine_ptr = 0;
 
void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight
)
{
    audio_chL = sine_table[sine_ptr]<<16;
	audio_chR = sine_table[sine_ptr]<<16;
    sine_ptr = (sine_ptr+1) % LOOP_SIZE;
	
    *outLeft = audio_chL;
    *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
