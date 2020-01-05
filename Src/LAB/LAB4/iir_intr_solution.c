// iir_intr.c
#include "LabCode.h"
#ifdef LAB4_IIR_SOL_INTR
#include <LAB/LAB4/Cauer_Filter_ba.h>

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;
// state variables:
//
float32_t wL[N_IIR] = {0};
float32_t wR[N_IIR] = {0};

int16_t k;                  // index for filter coefficients
float32_t gL, gR;           // output values


void Sample_Callback(int32_t inLeft, int32_t inRight,
                     int32_t* outLeft, int32_t* outRight)
{
  //register float32_t w;
  //
  // IIR Directform 2 Filter

  // initialize new value for state signal with new input sample
  wL[0] = (float32_t)(inLeft);// Compute only the left channel
  // initialize new value for output signal
  gL=0;
  //Compute samples from left to right, i.e. start with k = N_IIR - 1
  for (k = N_IIR-1; k>0 ; k--)
  {
    // compute new value for state signal using a[k]
    wL[0] -= a[k]*wL[k];
    // compute new value for output signal using b[k]
    gL += b[k]*wL[k];
    // shift wL[k-1] to wL[k]
    wL[k] = wL[k-1];
  }
  // k=0 still needs to be handled, since we started on the left (k=N_IIR-1)
  // we can immediately use the value for wL[0] computed by the loop above
  gL += b[0]*wL[0];

  *outLeft = (int32_t)(gL);
  //output the input signal from the left channel on the right channel of
  //the output to be able to compare the input and output signal of the filter
  *outRight = inLeft;
  // circularly increment interrupt counter
  if (++interrupt_counter == CM)
  {
    interrupt_counter = 0;
  }
  cycles_btwn_irs[interrupt_counter] = 0;
}


void Init()
{
    AudioInitIT(hz48000, line_in, Sample_Callback);
}

#endif
