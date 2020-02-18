/**
 *****************************************************************************
 * @file    wm8994_config.h
 * @brief   Configuration for audio codec WM8994
 * @author  Daniel Lohmann
 ******************************************************************************
 *
 */

#ifndef __WM8994_CONFIG_H
#define __WM8994_CONFIG_H

#include "main.h"
#include "stdint.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_def.h"
#include "stm32f7xx_hal_i2c.h"

#define CODEC_ADDRESS 52

#define WM8994_FREQ_8K 0
#define WM8994_FREQ_11_025K 1
#define WM8994_FREQ_12K 2
#define WM8994_FREQ_16K 3
#define WM8994_FREQ_22_05K 4
#define WM8994_FREQ_24K 5
#define WM8994_FREQ_32K 6
#define WM8994_FREQ_44_1K 7
#define WM8994_FREQ_48K 8

#define WM8994_INPUT_LINE1 (1 << 4) // Signal from time slot 0
#define WM8994_INPUT_SLOT2 (2 << 4) // Signal from time slot 1
#define WM8994_INPUT_LINE1_30DB (WM8994_INPUT_LINE1 + 1)
#define WM8994_INPUT_LINE1_60DB (WM8994_INPUT_LINE1 + 2)
/**
 * Initializes the audio codec WM8994 to sample the analog signal from the
 * audio in jack (blue) and sending to through AIF1 to the STM32 Controller
 * The samples which are sent from the STM Controller will be played via the
 * audio line out jack (green)
 * @param   configInterface: I2C-Interface which will be used for communication
 with the audio codec WM8994.
 * @param   frequencySelection: selected frequency
            The possible values are:
            WM8994_FREQ_8K, WM8994_FREQ_11_025K, WM8994_FREQ_12K,
 WM8994_FREQ_16K, WM8994_FREQ_22_05K, WM8994_FREQ_24K, WM8994_FREQ_32K,
 WM8994_FREQ_44_1K, WM8994_FREQ_48K

 * @param   inputSelection: selected input
            As input selection the line in and/or the digital microphone could
 be used. For selecting the line in input the defines WM8994_INPUT_LINE1,
 WM8994_INPUT_LINE1_30DB and WM8994_INPUT_LINE1_60DB could be used. For the
 digital microphone WM8994_INPUT_MIC would be used. A binary or combination
            allows the use of both inputs.
            Not on all STM32F7 boards the microphones are connected to the
 audio-codec, therefore this option cloud not be used on all boards.

 */
void InitAudioCodec(I2C_HandleTypeDef *configInterface,
                    uint8_t frequencySelection, uint8_t inputSelection);

/**
 * @brief Write the content of a register
 *
 * @param codecRegister Address of register
 *
 * @retval Returns the status of the I2C write operation
 */
HAL_StatusTypeDef WriteRegister(uint16_t codecRegister, uint16_t content);

/**
 * @brief Reads the content of a register
 *
 * @param codecRegister Address of the register
 *
 * @retval returns the read value
 */
uint16_t ReadRegister(uint16_t codecRegister);

/**
 * @brief Sets bits in an register on the audio codec to one
 *
 * @param codecRegister Address of the register
 * @param bits Bitmaks of bits which will b set to one
 *
 * @retval Returns the value which was written into the register
 */
uint16_t SetRegisterBits(uint16_t codecRegister, uint16_t bits);

/**
 * @brief Sets bits in an register on the audio codec to zero
 *
 * @param codecRegister Address of the register
 * @param bits Bitmask of bits which will be set to zero
 *
 * @retval  Returns the value which was written into the register
 */
uint16_t UnsetRegisterBits(uint16_t codecRegister, uint16_t bits);

/**
 * @brief Runs a programmed sequence on the audio codec
 *
 * @param   sequence index of sequence, for the default sequences the following
 parameters could be used: HEADPHONE_COLD_START_UP_START_INDEX,
 HEADPHONE_WARM_START_UP_START_INDEX, SPEAKER_STARP_UP_START_INDEX,
 EARPIECE_START_UP_START_INDEX, LINE_OUTPUT_START_UP_START_INDEX,
 SPEAKER_AND_HEADPHONE_FAST_SHUT_DOWN_START_INDEX, GENERIC_SHUTDOWN_START_INDEX.
            For custom defines sequences the value for the WSEQ_START_INDEX
 register used be used
 */
void RunSequence(uint16_t sequence);

/**
 * @brief Processes interrupts from the audio codec
 */
void wm8994_InterruptProcess();

#endif
