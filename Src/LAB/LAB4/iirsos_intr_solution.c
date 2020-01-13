// iirsos_intr.c
#include "LabCode.h"
#ifdef LAB4_IIRSOS_SOL_INTR
#include <LAB/LAB4/Cauer_Filter_sos.h>

volatile int32_t audio_chR=0;
volatile int32_t audio_chL=0;
// state variables:
//
float wL[NUM_SECTIONS][3] = {0};
float wR[NUM_SECTIONS][3] = {0};

int32_t audio_out_chL = 0;
int32_t audio_out_chR = 0;
int16_t section;            // index for section number
float32_t inputL, inputR;   // input to each section
float32_t gLn, gRn;         // intermediate and output values


void Sample_Callback(int32_t inLeft, int32_t inRight,
                     int32_t* outLeft, int32_t* outRight)
{

  // Compute the left channel
  inputL = (float32_t)(inLeft);  // Compute only the left channel
  // Loop over sections
  for (section=0 ; section< NUM_SECTIONS ; section++)
  {
    // Compute new value for state signal using a[1] and a[2] coefficients
    wL[section][0] = inputL - a[section][1]*wL[section][1]
                     - a[section][2]*wL[section][2];
    // Compute new value for the output signal using the b[k] coefficients
    gLn = b[section][0]*wL[section][0] + b[section][1]*wL[section][1]
          + b[section][2]*wL[section][2];
    // Shift state signal
    wL[section][2] = wL[section][1];
    wL[section][1] = wL[section][0];
    inputL = gLn; // output of current section is input to next
  }
  *outLeft = (int32_t)(gLn);
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
