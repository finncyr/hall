// loop_buf_intr.c 
#include "LabCode.h"

#ifdef LAB2_LOOP_BUF_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define BUFFER_SIZE 256

float32_t rbuffer[BUFFER_SIZE];
int32_t rbufptr = 0;
float32_t lbuffer[BUFFER_SIZE];
int32_t lbufptr = 0;

void Sample_Callback(
	uint32_t inLeft,
	uint32_t inRight,
	uint32_t* outLeft,
	uint32_t* outRight
)
{
	audio_chL = inLeft;
	audio_chR = inRight;

	lbuffer[lbufptr] = (float32_t)(audio_chL);
	rbuffer[rbufptr] = (float32_t)(audio_chR);
	lbufptr = (lbufptr+1) % BUFFER_SIZE;
	rbufptr = (rbufptr+1) % BUFFER_SIZE;
	
	*outLeft = audio_chL;
	*outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
