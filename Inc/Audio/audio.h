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

#include "arm_const_structs.h"
#include "stm32f7xx_hal.h"
#include "Audio/wm8994_config.h"
#include <stdbool.h>
#include "stdint.h"

#define AUDIO_DMA
//#define AUDIO_IT

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

/*! \brief Creates a pseudo-random value at 16bit basis*/
short prbs(void);

#ifdef AUDIO_DMA
/**
 * Define the size of the input and output ping/pong buffers for audio DMA
 * Thus each buffer contains BUFFER_SIZE samples. In the case of 2 audio
 * channels (stereo), the samples for the left and the right channel are
 * interleaved. This means that the buffers contain  BUFFER_SIZE / 2 samples
 * per channel!
 */
// Defined the size of the input and output buffers for audio DMA
//#define BUFFER_SIZE 128
//#define BUFFER_SIZE 256
//#define BUFFER_SIZE 512
//#define BUFFER_SIZE 1024
#define BUFFER_SIZE 4096
//#define BUFFER_SIZE 8192
//#define BUFFER_SIZE 16384

#define __D ((BUFFER_SIZE / 2)*2)
#if __D == BUFFER_SIZE

#else
#error BUFFER_SIZE must be an even value for stereo audio
#endif

/**
 * Struct which handles a pair of an input and output buffer to DMA ping/pong operation
 */
typedef struct  {
    /**
     * @brief Audio input buffer
     * @details Right and Left channel are alternating contained in the buffer.
     * The length of the buffer is @ref BUFFER_SIZE
     */
    int32_t* Input;
    /**
     * @brief Audio output buffer
     * @details Right and Left channel are alternating contained in the buffer.
     * The length of the buffer is @ref BUFFER_SIZE
     */
    int32_t* Output;
} AudioDMABuffer_t;

extern int32_t* transmitBuffer;
/**
 * Object of type AudioDMABuffer_t which always points to the buffers used for processing
 */
extern AudioDMABuffer_t ProcessingBuffer;
/**
 * The sampling rate used in Hz
 */
extern float32_t SamplingRateHz;
/**
 * @brief Initializes the SAI and the audio codec for dma use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or default is line_in
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param half_Callback     Callback for the half completion of transfer
 * @param full_Callback     Callback for the full completion of transfer
 */
void AudioInitDMA(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*half_Callback)(),
    void (*full_Callback)()
);

#endif

#ifdef AUDIO_IT

/**
 * @brief Initializes the SAI and the audio codec for sample interrupt use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or default is line_in
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param sample_Callback   Callback for an audio sample pair
 */
HAL_StatusTypeDef AudioInitIT(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*sample_Callback)(uint32_t inLeft, uint32_t inRight, uint32_t* outLeft, uint32_t* outRight)
);

#endif

#endif
