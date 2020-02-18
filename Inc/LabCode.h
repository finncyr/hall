#ifndef __LABCODE_H
#define __LABCODE_H

//#define ARM_MATH_CM7

#include "Audio/audio.h"
#include "Audio/wm8994_config.h"

//#include <core_cm7.h>
//#include <arm_math.h>

typedef float float32_t;

void Init();
void setBuffer(AudioDMABuffer_t *);

extern bool data_available;
extern bool processing_data;
#define CM 10
// array for storing the loop cycles between interrupts
extern uint32_t cycles_btwn_irs[CM];
extern uint16_t interrupt_counter; // counter for the interrupts

// Make sure that only one of the following defines is used!!
//#define LAB5_FFT
#define LAB5_FFT_ARM
//#define LAB5_LOOP_DMA
#endif
