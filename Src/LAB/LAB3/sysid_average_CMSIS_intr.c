// sysid_average_CMSIS_intr.c
#include "LabCode.h"

#ifdef LAB3_SYSID_AVERAGE_CMSIS_INTR

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;

#define BLOCK_SIZE 1 // belongs to adaptive filter (UwD)
#define NUM_TAPS 256  // belongs to adaptive filter (UwD)

#define N 5

float32_t h[N];
float32_t x[N];
float32_t beta = 1E-12;
float32_t firStateF32[BLOCK_SIZE + NUM_TAPS - 1];
float32_t firCoeffs32[NUM_TAPS] = { 0.0f };
arm_lms_instance_f32 S;
float32_t adapt_in, adapt_out, adapt_err,input;
float32_t fir_out;

void Sample_Callback(
  uint32_t inLeft,
  uint32_t inRight,
  uint32_t* outLeft,
  uint32_t* outRight
)
{	
  int32_t audio_out_chL = 0;
  int32_t audio_out_chR = 0;
  int16_t i;
    
  audio_chL = inLeft;
  audio_chR = inRight;

  input = (float32_t)(audio_chL);
  adapt_in = (float32_t)(prbs());
	
  x[0] = adapt_in;
  fir_out = 0.0;
  for (i = N-1; i>= 0; i--)
  {
	fir_out +=(h[i]*x[i]);
	x[i+1] = x[i];   // actual sample is x[0]!! shift samples by one back in time (UwD)
  }
	
  audio_out_chL = (int16_t)(fir_out)<<16;
  audio_out_chR = 0;
      
  *outLeft = audio_out_chL;
  *outRight = audio_out_chR;

  arm_lms_f32(&S, &adapt_in, &input, &adapt_out, &adapt_err, BLOCK_SIZE);	
}

void Init()
{
  int i;
  
  for (i=0 ; i<N ; i++) {
    h[i] = 1.0/N;
  }

  arm_lms_init_f32(&S, NUM_TAPS, (float32_t *)&firCoeffs32[0], &firStateF32[0], beta, BLOCK_SIZE);
  
  AudioInitIT(hz8000, line_in,
      Sample_Callback);
}

#endif


