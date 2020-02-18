/*
 * fft.h
 *
 *  Created on: 12.11.2018
 *      Author: elders
 */

#ifndef __AUDIO_FFT_H
#define __AUDIO_FFT_H

#include "Audio/audio.h"
#include "arm_const_structs.h"

#define FFT_SIZE (BUFFER_SIZE / 2)        // Don't ever remove the brackets!!!!
extern float32_t fft_buffer[BUFFER_SIZE]; // fft input and output buffer

extern uint32_t fft_counter;

/**
 * @brief Initialize the FFT
 *
 */
void FFT();
/**
 * @brief Calculate the FFT
 *
 */
void Init_FFT();
/**
 * @brief Copy audio DMA buffer to FFT buffer
 *
 * @param channel     Select channel
 */
void Copy_To_FFT_Buffer(int32_t *);

#endif /* __AUDIO_FFT_H */
