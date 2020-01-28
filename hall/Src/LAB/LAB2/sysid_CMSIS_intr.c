// sysid_CMSIS_intr.c
#include "LabCode.h"

#ifdef LAB2_SYSID_CMSIS_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

#define BLOCK_SIZE 1
#define NUM_TAPS 256

float32_t beta = 1E-12;
float32_t firStateF32[BLOCK_SIZE + NUM_TAPS - 1];
float32_t firCoeffs32[NUM_TAPS] = { 0.0f };
arm_lms_instance_f32 S;
float32_t adapt_in, adapt_out, adapt_err,input,wn;


void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight
)
{
	int16_t audio_out_chR = 0;
	int16_t audio_out_chL = 0;

	audio_chL = inLeft;
    audio_chR = inRight;

	input = (float32_t)(audio_chL);
	adapt_in = (float32_t)(prbs());
	audio_out_chL = (int16_t)(adapt_in);
	audio_out_chR = 0;
	
	*outLeft = audio_out_chL<<16;
	*outRight = audio_out_chR<<16;
		
	arm_lms_f32(&S, &adapt_in, &input, &adapt_out, &adapt_err, BLOCK_SIZE);
}

void Init()
{
	arm_lms_init_f32(&S, NUM_TAPS, (float32_t *)&firCoeffs32[0], &firStateF32[0], beta, BLOCK_SIZE);

	AudioInitIT(hz8000, line_in,
        Sample_Callback);
}

#endif
