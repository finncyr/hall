/**
 *****************************************************************************
 * @file    audio.h
 * @brief   Audio handling of with WM8994 Codec
 * @author  Daniel Lohmann
 ****************************************************************************** 
 * 
 */

#ifndef __AUDIO_H
#define __AUDIO_H

#include "stm32f7xx_hal.h"
#include "Audio/wm8994_config.h"
#include <stdbool.h>

//#define AUDIO_DMA
#define AUDIO_IT

#define hz48000 WM8994_FREQ_48K
#define hz44100	WM8994_FREQ_44_1K
#define hz32000	WM8994_FREQ_32K
#define hz24000	WM8994_FREQ_24K
#define hz22050	WM8994_FREQ_22_05K
#define hz16000	WM8994_FREQ_16K
#define hz12000	WM8994_FREQ_12K
#define hz11025	WM8994_FREQ_11_025K
#define hz8000	WM8994_FREQ_8K

#define slot1_in  	WM8994_INPUT_SLOT2 //Signal from time slot 1
#define line_in 	WM8994_INPUT_LINE1 //Signal from time slot 0

#define NOISELEVEL 8000

/*! \brief Creates a pseud-random value at 16bit basis*/
short prbs(void);

#ifdef AUDIO_DMA

#define BUFFER_SIZE 128

#define __D ((BUFFER_SIZE / 2)*2)
#if __D == BUFFER_SIZE

#else
    #error BUFFER_SIZE must be an even value for stereo audio
#endif

/** 
 * Struct which handles a pair of an input and ouput buffer to DMA ping/pong operation
 */
typedef struct  {
    /** 
     * @brief Audio input buffer
     * @details Right and Left channel are alternating contained in the buffer.
     * The length of the buffer is @ref BUFFER_SIZE
     */
    uint32_t* Input;
    /** 
     * @brief Audio output buffer
     * @details Right and Left channel are alternating contained in the buffer.
     * The length of the buffer is @ref BUFFER_SIZE
     */
    uint32_t* Output;
} AudioDMABuffer_t;

/**
 * @brief Initialises the SAI and the audio codec for dma use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or default is line_in
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param half_Callback     Callback for the half completion of transfer
 * @param full_Callback     Callback for the full completion of transfer
 */
void AudioInitDMA(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*half_Callback)(AudioDMABuffer_t* buffer),
    void (*full_Callback)(AudioDMABuffer_t* buffer)
);

#endif

#ifdef AUDIO_IT

/**
 * @brief Initialises the SAI and the audio codec for sample interrupt use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or default is line_in
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param sample_Callback   Callback for an audio sample pair
 */
HAL_StatusTypeDef AudioInitIT(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*sample_Callback)(int32_t inLeft, int32_t inRight, int32_t* outLeft, int32_t* outRight)
);

#endif

#endif 
