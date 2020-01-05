/**
 *****************************************************************************
 * @file    wm8994_config.c
 * @brief   Configuration for audio codec WM8994
 * @author  Daniel Lohmann
 ****************************************************************************** 
 * 
 */
 
#include "Audio/wm8994_config.h"
#include "Audio/wm8994_RegisterDefines.h"

I2C_HandleTypeDef* hi2cConfigInterface = NULL;

/** 
 * Initializes the audio codec WM8994 to sample the analog signal from the
 * audio in jack (blue) and sending to thrue AIF1 to the STM32 Controller 
 * The samples which are sent from the STM Controller will be played via the 
 * audio line out jack (green)
 * @param   configInterface: I2C-Interface which will be used for communication with the audio codec WM8994.
 * @param   frequencySelection: selected frequency
            The possible values are:
            WM8994_FREQ_8K, WM8994_FREQ_11_025K, WM8994_FREQ_12K, WM8994_FREQ_16K,
            WM8994_FREQ_22_05K, WM8994_FREQ_24K, WM8994_FREQ_32K, WM8994_FREQ_44_1K,
            WM8994_FREQ_48K

 * @param   inputSelection: selected frequency
            As input selection the line in and/or the digital microphone could be used. For selecting the
            line in input the defines WM8994_INPUT_LINE1, WM8994_INPUT_LINE1_30DB and WM8994_INPUT_LINE1_60DB
            could be used. For the digital microphone WM8994_INPUT_MIC would be used. A binary or combination 
            allows the use of both inputs.

 */
void InitAudioCodec(I2C_HandleTypeDef* configInterface, uint8_t frequencySelection, uint8_t inputSelection)
{
    // Remember the configuration interface for later use
    hi2cConfigInterface = configInterface; 

    //Do a software reset
    WriteRegister(SOFTWARE_RESET_REG, 0xFFFF);

    //read device family ID (should be 0x8994)
    uint16_t familyID = ReadRegister(FAMILY_ID_REG);
    if (familyID != FAMILY_ID)
    {
        return; //AudioCodec indicates another device than expected!
    }

    uint8_t revision = (uint8_t)((ReadRegister(CHIP_REVISION_REG) & CHIP_REV_bm) >> CHIP_REV_bp);
    if (revision == 3)
    {
    	//Revision D
    }

    //set the sample rate on audio interface 1 according to the user selection
    switch (frequencySelection)
    {
        case WM8994_FREQ_8K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_8K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_11_025K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_11_025K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_12K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_12K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_16K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_16K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_22_05K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_22_025K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_24K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_24K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_32K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_32K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_44_1K:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_44_1K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
        case WM8994_FREQ_48K:
        default:
            WriteRegister(AIF1_RATE_REG, AIF1_SR_48K << AIF1_SR_bp | AIF1CLK_RATE_256 << AIF1CLK_RATE_bp);
            break;
    }
    
    //Oversampling is not for all frequencies available
    //see table 14 and 15 from data sheet for further information
    if (frequencySelection >= WM8994_FREQ_16K) 
    {   
        WriteRegister(OVERSAMPLING_REG, ADC_OSR128_bm);
    }
    else
    {
        WriteRegister(OVERSAMPLING_REG, 0); 
    }

    uint8_t rateStatus = (uint8_t)((ReadRegister(RATE_STATUS_REG) & SR_ERROR_bm) >> SR_ERROR_bp);
    if (rateStatus != SR_ERROR_NO_ERROR)
    {
    	return; //Problem with clock configuration
    }

    // Configure Sysclock
    WriteRegister(AIF1_CLOCKING_1_REG,
    	AIF1CLK_SRC_MCLK1 << AIF1CLK_SRC_bp | AIF1CLK_ENA_bm);

    WriteRegister(CLOCKING_1_REG,
    	SYSDSPCLK_ENA_bm | AIF1DSPCLK_ENA_bm);

    // Configure path through the audio codec
    if (inputSelection & WM8994_INPUT_LINE1)
    {
		//---Input PGA---
		SetRegisterBits(POWER_MANAGEMENT_2_REG, IN1L_ENA_bm | IN1R_ENA_bm);

		SetRegisterBits(INPUT_MIXER_2_REG, IN1LN_TO_IN1L_bm | IN1RN_TO_IN1R_bm);

		UnsetRegisterBits(LEFT_LINE_INPUT_1_2_VOLUME_REG, IN1L_MUTE_bm);
		UnsetRegisterBits(RIGHT_LINE_INPUT_1_2_VOLUME_REG, IN1R_MUTE_bm);

		if (inputSelection == WM8994_INPUT_LINE1_30DB || //Boost Volume on PGA1
			inputSelection == WM8994_INPUT_LINE1_60DB)
		{
			SetRegisterBits(LEFT_LINE_INPUT_1_2_VOLUME_REG, 0x1F);
			SetRegisterBits(RIGHT_LINE_INPUT_1_2_VOLUME_REG, 0x1F | IN1L_VU_bm);
		}

		UnsetRegisterBits(LEFT_LINE_INPUT_3_4_VOLUME_REG, IN2L_MUTE_bm);
		SetRegisterBits(LEFT_LINE_INPUT_3_4_VOLUME_REG, IN2L_MUTE_bm);

		UnsetRegisterBits(RIGHT_LINE_INPUT_3_4_VOLUME_REG, IN2R_MUTE_bm);
		SetRegisterBits(RIGHT_LINE_INPUT_3_4_VOLUME_REG, IN2R_MUTE_bm);

		//---Input Mixer---
		SetRegisterBits(POWER_MANAGEMENT_2_REG, MIXINL_ENA_bm | MIXINR_ENA_bm);

		SetRegisterBits(INPUT_MIXER_3_REG, IN1L_TO_MIXINL_bm);
		SetRegisterBits(INPUT_MIXER_4_REG, IN1R_TO_MIXINR_bm);

		if (inputSelection == WM8994_INPUT_LINE1_60DB) //Boost Volume on input mixer
		{
			SetRegisterBits(INPUT_MIXER_3_REG, IN1L_MIXINL_VOL_bm);
			SetRegisterBits(INPUT_MIXER_4_REG, IN1R_MIXINR_VOL_bm);
		}

		//---ADC---
		SetRegisterBits(POWER_MANAGEMENT_4_REG, ADCL_ENA_bm | ADCR_ENA_bm);

		//---AIF1 ADC Timeslot 0---
		SetRegisterBits(POWER_MANAGEMENT_4_REG, AIF1ADC1L_ENA_bm | AIF1ADC1R_ENA_bm);
		
		SetRegisterBits(ADC1_LEFT_MIXER_ROUTING_REG, ADC1L_TO_AIF1ADC1L_bm);
		SetRegisterBits(ADC1_RIGHT_MIXER_ROUTING_REG, ADC1R_TO_AIF1ADC1R_bm);
    }
    if (inputSelection & WM8994_INPUT_SLOT2)
    {
    	SetRegisterBits(POWER_MANAGEMENT_1_REG, MICB1_ENA_bm);

        //---AIF1 ADC Timeslot 1---
    	SetRegisterBits(POWER_MANAGEMENT_4_REG, AIF1ADC2L_ENA_bm | AIF1ADC2R_ENA_bm | DMIC2L_ENA_bm | DMIC2R_ENA_bm);

    	SetRegisterBits(ADC2_LEFT_MIXER_ROUTING_REG, ADC2L_TO_AIF1ADC2L_bm);
    	SetRegisterBits(ADC2_RIGHT_MIXER_ROUTING_REG, ADC2R_TO_AIF1ADC2R_bm);

    	WriteRegister(AIF1ADC2_LEFT_VOLUME_REG, AIF1ADC2L_VU_bm | 0x80);
    	WriteRegister(AIF1ADC2_RIGHT_VOLUME_REG, AIF1ADC2R_VU_bm| 0x80);
    }

    //---AIF1 DAC Timesolt 0---
    SetRegisterBits(POWER_MANAGEMENT_5_REG, AIF1DAC1L_ENA_bm | AIF1DAC1R_ENA_bm);

    SetRegisterBits(AIF1ADC1_LEFT_VOLUME_REG, AIF1ADC1L_VU_bm);
    SetRegisterBits(AIF1ADC1_RIGHT_VOLUME_REG, AIF1ADC1R_VU_bm);

    //SetRegisterBits(AIF1_CONTROL_2_REG, AIF1_LOOPBACK_bm);

    //Change away from default to allow use of LRCLK
    //Set it to IRQ for interrupt use
    WriteRegister(GPIO_1_REG, GP1_FN_IRQ); 

	//---DAC---
	SetRegisterBits(POWER_MANAGEMENT_5_REG, DAC1L_ENA_bm | DAC1R_ENA_bm);

	SetRegisterBits(DAC1_LEFT_MIXER_ROUTING_REG, AIF1DAC1L_TO_DAC1L_bm);
	SetRegisterBits(DAC1_RIGHT_MIXER_ROUTING_REG, AIF1DAC1R_TO_DAC1R_bm);

	{ 	//Test: Digital Audio Path without AIF1
		//SetRegisterBits(DAC1_LEFT_MIXER_ROUTING_REG, ADCL_TO_DAC1L_bm);
		//SetRegisterBits(DAC1_RIGHT_MIXER_ROUTING_REG, ADCR_TO_DAC1R_bm);
		//WriteRegister(DAC1_MIXER_REG, 0x1EF); //ADCR/ADCL direct Volume
	}

	UnsetRegisterBits(DAC1_LEFT_REG, DAC1L_MUTE_bm);
	UnsetRegisterBits(DAC1_RIGHT_REG, DAC1R_MUTE_bm);

	UnsetRegisterBits(AIF1DAC1_FILTERS_1_REG, AIF1DAC1_MUTE_bm);

	//---Headphone Output---
	SetRegisterBits(OUTPUT_MIXER_1_REG, DAC1L_TO_HPOUT1L_bm);
	SetRegisterBits(OUTPUT_MIXER_2_REG, DAC1R_TO_HPOUT1R_bm);

	{   //Test: Analog Path 1
		//SetRegisterBits(POWER_MANAGEMENT_3_REG, MIXOUTLVOL_ENA_bm | MIXOUTRVOL_ENA_bm | MIXOUTL_ENA_bm | MIXOUTR_ENA_bm);
		//SetRegisterBits(OUTPUT_MIXER_1_REG, IN1L_TO_MIXOUTL_bm);
		//SetRegisterBits(OUTPUT_MIXER_2_REG, IN1R_TO_MIXOUTR_bm);
	}
	{   //Test: Analog Path 2
		//SetRegisterBits(POWER_MANAGEMENT_3_REG, MIXOUTLVOL_ENA_bm | MIXOUTRVOL_ENA_bm | MIXOUTL_ENA_bm | MIXOUTR_ENA_bm);
		//SetRegisterBits(OUTPUT_MIXER_1_REG, MIXINL_TO_MIXOUTL_bm);
		//SetRegisterBits(OUTPUT_MIXER_2_REG, MIXINR_TO_MIXOUTR_bm);
	}

	//Change Output Volume to 0dB (input = output amplitude)
	WriteRegister(LEFT_OUTPUT_VOLUME_REG, HPOUT1L_VU_bm | HPOUT1L_MUTE_bm | 0x39);
	WriteRegister(RIGHT_OUTPUT_VOLUME_REG, HPOUT1R_VU_bm | HPOUT1R_MUTE_bm | 0x39);

    // Configure the headphone output
    RunSequence(HEADPHONE_COLD_START_UP_START_INDEX);

    //TODO: maybe look at interrupt handling for WM8994, GPIO1 is already configured for interrupt use
}

/**
 * @biref Write the content of a register
 * 
 * @param codecRegister Address of register
 *
 * @retval Returns the status of the I2C write operation
 */
HAL_StatusTypeDef WriteRegister(uint16_t codecRegister, uint16_t content)
{
	const uint16_t deviceAddress = CODEC_ADDRESS;
    uint8_t buffer[2]; 							//content is little-endian encoded but big-endian is required
    buffer[0] = (content >> 8) & 0x00FF;        //register address B15-A8
    buffer[1] = content & 0x00FF;               //register address B7-B0

    HAL_StatusTypeDef status = HAL_OK;
    status = HAL_I2C_Mem_Write(hi2cConfigInterface, deviceAddress, codecRegister, I2C_MEMADD_SIZE_16BIT, buffer, 2, 1000);

#ifdef CHECK_WRITTEN
    uint16_t readValue = ReadRegister(deviceAddress, codecRegister);
    if (readValue != content)
    {
        status = HAL_ERROR; //written and read value are different
    }
#endif

    return status;
}

/**
 * @brief Reads the content of a register
 * 
 * @param codecRegister Address of the register
 *
 * @retval returns the read value
 */
uint16_t ReadRegister(uint16_t codecRegister)
{
	const uint16_t deviceAddress = CODEC_ADDRESS;
    uint8_t buffer[2];
    uint16_t content = 0;
    HAL_I2C_Mem_Read(
        hi2cConfigInterface,
        deviceAddress,
		codecRegister,
        I2C_MEMADD_SIZE_16BIT,
        buffer,
        2,
        1000);
    
    //content is little-endian encoded but big-endian was received
    content = buffer[0] << 8 | buffer[1];
    return content;
}

/**
 * @brief Sets bits in an register on the audio codec to one
 * 
 * @param codecRegister Address of the register
 * @param bits Bitmaks of bits which will b set to one
 *
 * @retval Returns the value which was written into the register
 */
uint16_t SetRegisterBits(uint16_t codecRegister, uint16_t bits)
{
	uint16_t content = ReadRegister(codecRegister);
	content = content | bits;
	WriteRegister(codecRegister, content);
	return content;
}

/**
 * @brief Sets bits in an register on the audio codec to zero
 * 
 * @param codecRegister Address of the register
 * @param bits Bitmask of bits which will be set to zero
 *
 * @retval  Returns the value which was written into the register
 */
uint16_t UnsetRegisterBits(uint16_t codecRegister, uint16_t bits)
{
	uint16_t content = ReadRegister(codecRegister);
	content = content & ~bits;
	WriteRegister(codecRegister, content);
	return content;
}

/**
 * @brief Runs a programmed sequence on the audio codec
 * 
 * @param   sequence index of sequence, for the default sequences the following parameters could be used:
            HEADPHONE_COLD_START_UP_START_INDEX, HEADPHONE_WARM_START_UP_START_INDEX,
            SPEAKER_STARP_UP_START_INDEX, EARPIECE_START_UP_START_INDEX,
            LINE_OUTPUT_START_UP_START_INDEX, SPEAKER_AND_HEADPHONE_FAST_SHUT_DOWN_START_INDEX,
            GENERIC_SHUTDOWN_START_INDEX. 
            For custom defines sequences the value for the WSEQ_START_INDEX register used be used
 */
void RunSequence(uint16_t sequence)
{
	//Enable and Start bits needs to be set
	sequence |= WSEQ_START_bm | WSEQ_ENA_bm;

	//Start the requested sequence
	WriteRegister(WRITE_SEQUENCER_CONTROL_1_REG, sequence);

	//Wait for finishing of the sequence
	while (ReadRegister(WRITE_SEQUENCER_CONTROL_2_REG) && WSEQ_BUSY_bm) ;

	return;
}

/**
 * @brief Processes interrupts from the audio codec
 */
void wm8994_InterruptProcess()
{
	uint32_t irqstate1 = ReadRegister(INTERRUPT_STATUS_1_REG);
	uint32_t irqstate2 = ReadRegister(INTERRUPT_STATUS_2_REG);
	//In case of an interrupt from the audio codec it could be processed here!
}
