// sine_lut_buf_intr.c
#include <stdlib.h>
#include "LabCode.h"

#ifdef LAB2_SINE_LUT_BUF_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define LOOP_SIZE 8
#define BUFFER_SIZE 100
int16_t sine_table[LOOP_SIZE] = {0, 7071, 10000, 7071, 0, -7071, -10000, -7071};
static int sine_ptr = 0;

float buffer[BUFFER_SIZE];
static int buf_ptr=0;

void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight
)
{
    audio_chL = inLeft;
    audio_chR = inRight;

    audio_chL = sine_table[sine_ptr]<<16;
    audio_chR = sine_table[sine_ptr]<<16;
	buffer[buf_ptr]=sine_table[sine_ptr];
    sine_ptr = (sine_ptr+1) % LOOP_SIZE;
    buf_ptr = (buf_ptr+1) % BUFFER_SIZE;
	
    *outLeft = audio_chL;
    *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
