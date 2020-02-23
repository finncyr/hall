/*
 * fft.c
 *
 *  Created on: 12.11.2018
 *  Author: Harald Elders-Boll
 */
#include "LabCode.h"
#include "FFT/fft.h"
#ifdef LAB5_FFT_ARM
float32_t fft_buffer[BUFFER_SIZE];//fft input and output buffer

// define a pointer to an ARM FFT instance
arm_cfft_instance_f32* arm_cfft_instance = NULL;


void Init_FFT()
{
  switch (FFT_SIZE)
  {
    case 16:
      arm_cfft_instance = &arm_cfft_sR_f32_len16;
      break;
    case 32:
      arm_cfft_instance = &arm_cfft_sR_f32_len32;
      break;
    case 64:
      arm_cfft_instance = &arm_cfft_sR_f32_len64;
      break;
    case 128:
      arm_cfft_instance = &arm_cfft_sR_f32_len128;
      break;
    case 256:
      arm_cfft_instance = &arm_cfft_sR_f32_len256;
      break;
    case 512:
      arm_cfft_instance = &arm_cfft_sR_f32_len512;
      break;
    case 1024:
      arm_cfft_instance = &arm_cfft_sR_f32_len1024;
      break;
    case 2048:
      arm_cfft_instance = &arm_cfft_sR_f32_len2048;
      break;
    case 4096:
      arm_cfft_instance = &arm_cfft_sR_f32_len4096;
      break;
    default:
      arm_cfft_instance = NULL;
      break;
  }
}

// Calculate the FFT using an FFT instance of the desired FFT length
// FFT is computed in-place, i.e. the results is also stored in fft_buffer
// The input data is complex and contains 2*FFT_SIZE interleaved float values:
// {real[0], imag[0], real[1], imag[1],...}
void FFT()
{
  arm_cfft_f32(arm_cfft_instance, fft_buffer, 0, 1);
}

void Copy_To_FFT_Buffer(int32_t* buffer)
{
  // Copy from processing buffer to fft_buffer and convert from int32_t
  // to float32_t. q31 is an ARM CMSIS DSP fractional type equivalent to int32_t
  // but results are scaled by 1/(2**31). Thus resulting floating point values
  // are between -1.0 and 1.0
  arm_q31_to_float(buffer, fft_buffer, BUFFER_SIZE);
}
#endif
