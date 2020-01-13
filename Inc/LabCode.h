#ifndef __LABCODE_H
#define __LABCODE_H

#define ARM_MATH_CM7

#include "Audio/wm8994_config.h"
#include "Audio/audio.h"
#include <core_cm7.h>
#include <arm_math.h>

typedef float float32_t;

void Init();
#define CM 10
//array for storing the loop cycles between interrupts
extern uint32_t cycles_btwn_irs[CM];
extern uint16_t interrupt_counter; //counter for the interrupts

#define LAB1
#define LAB2
#define LAB3
#define LAB4
#define LAB5
//
#ifdef LAB1
//#define LAB1_LOOP_INTR
//#define LAB1_DELAY_INTR
//#define LAB1_ECHO_INTR
//#define LAB1_SINE_LUT_INTR
//#define LAB1_SINE_LUT_BUF_INTR

#define LAB1_REVERB_INTR

#endif

#ifdef LAB2
//#define LAB2_SINE_INTR
//#define LAB2_SINE_LUT_INTR
//#define LAB2_SQUARE_INTR
//#define LAB2_DIMPULSE_INTR
//#define LAB2_PRBS_INTR
//#define LAB2_LOOP_BUF_INTR

//#define LAB2_LOOP_INTR
//#define LAB2_SINE_LUT_BUF_INTR
//#define LAB2_SYSID_CMSIS_INTR
#endif

#ifdef LAB3
//#define LAB3_AVERAGE_INTR
//#define LAB3_AVERAGE_PRBS_INTR
//#define LAB3_FIR_INTR
//#define LAB3_FIR_PRBS_INTR


//#define LAB3_FIR_PRBS_CMSIS_INTR
//#define LAB3_FIR_PRBS_CMSIS_DMA 		//In DMA project
//#define LAB3_FIR_PRBS_DMA 			//In DMA project
//#define LAB3_LOOP_INTR
//#define LAB3_SYSID_AVERAGE_CMSIS_INTR
//#define LAB3_SYSID_CMSIS_INTR
#endif

#ifdef LAB4
//#define LAB4_IIR_INTR
//#define LAB4_IIRSOS_INTR
#define LAB4_IIR_SOL_INTR
//#define LAB4_IIRSOS_SOL_INTR
//#define LAB4_LOOP_INTR
#endif

#ifdef LAB5
// look at DMA based project
#endif

#endif


