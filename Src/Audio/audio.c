/**
 *****************************************************************************
 * @file    audio.c
 * @brief   Audio handling of with WM8994 Codec
 * @author  Daniel Lohmann
 ****************************************************************************** 
 * 
 */

#include "main.h"
#include "stm32f7xx_hal.h"
#include "Audio/audio.h"
#include "Audio/wm8994_config.h"

extern SAI_HandleTypeDef hsai_BlockA1;
extern SAI_HandleTypeDef hsai_BlockB1;
extern I2C_HandleTypeDef hi2c4;
uint8_t input;
float32_t SamplingRateHz;

#ifdef AUDIO_DMA
int32_t bufferTransmit[BUFFER_SIZE * 2];
int32_t bufferReceive[BUFFER_SIZE * 2];

void (*ptrHalf_Callback)() = NULL;
void (*ptrFull_Callback)() = NULL;

int32_t* transmitBuffer = bufferTransmit;
AudioDMABuffer_t ProcessingBuffer;

void HAL_SAI_TxCpltCallback(SAI_HandleTypeDef* hsai)
{
	transmitBuffer = bufferTransmit + BUFFER_SIZE;
}

void HAL_SAI_TxHalfCpltCallback(SAI_HandleTypeDef* hsai)
{
	transmitBuffer = bufferTransmit;
}

void HAL_SAI_RxHalfCpltCallback(SAI_HandleTypeDef* hsai)
{
    ProcessingBuffer.Input = bufferReceive;
    ProcessingBuffer.Output = transmitBuffer;
    if (ptrHalf_Callback != NULL)
    {
        ptrHalf_Callback();
    }
}

void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef* hsai)
{
    ProcessingBuffer.Input = bufferReceive + BUFFER_SIZE;
    ProcessingBuffer.Output = transmitBuffer;
    
    if (ptrFull_Callback != NULL)
    {
        ptrFull_Callback();
    }
}

void HAL_SAI_ErrorCallback(SAI_HandleTypeDef* hsai)
{
	HAL_SAI_StateTypeDef state = HAL_SAI_GetState(hsai);
	uint32_t error = HAL_SAI_GetError(hsai);
}
#endif

#ifdef AUDIO_IT
/**
 * @brief Interrupt handler for a sample based processing
 *
 * @param	inLeft		sample from the left channel.
 * 						When only line is used the samples come from the line in left channel.
 * 						When using mic in only the samples come from the left microphone
 * 						When both inputs are used the samples come from the left microphone
 * @param	inRight		sample from the right channel.
 * 						When only line is used the samples come from the line in right channel.
 * 						When using mic in only the samples come from the right microphone
 * 						When both inputs are used the samples come from the right microphone
 * @param 	outLeft		Pointer to sample storage for the left channel
 * 						All the time this is the output value for the left channel
 * 						When both inputs are used also the in samples are provided in this storage
 * @param 	outRight	Pointer to sample storage for the right channel
 * 						All the time this is the output value for the right channel
 * 						When both inputs are used also the in samples are provided in this storage
 */
void (*ptrSample_Callback)(uint32_t inLeft, uint32_t inRight, uint32_t* outLeft, uint32_t* outRight) = NULL;

void SAI_IT(SAI_HandleTypeDef *hsai)
{
	if (((hsai_BlockB1.Instance->SR & SAI_xSR_FLVL) >> 16) > 1)
	{
    SAI_HandleTypeDef *hsai = &hsai_BlockB1;
    uint32_t inleft = 0;
    uint32_t inright = 0;
    uint32_t outleft = 0;
    uint32_t outright = 0;

    if (input & WM8994_INPUT_SLOT2) //When the microphones are switched on time slot 1 is also used
    {
      inleft =  (hsai->Instance->DR)<<8;
      outleft = (hsai->Instance->DR)<<8;
      inright = (hsai->Instance->DR)<<8;
      outright = (hsai->Instance->DR)<<8;
    }
    else
    {
      inleft =  (hsai->Instance->DR)<<8;
      inright = (hsai->Instance->DR)<<8;
    }

    if (ptrSample_Callback != NULL)
    {
        //call audio processing routine
        ptrSample_Callback(inleft, inright, &outleft, & outright);
    }

		if (input & WM8994_INPUT_SLOT2) //When the microphones are switched on time slot 1 is also used
		{
			hsai_BlockA1.Instance->DR = outleft>>8;
			hsai_BlockA1.Instance->DR = outleft>>8;
			hsai_BlockA1.Instance->DR = outright>>8;
			hsai_BlockA1.Instance->DR = outright>>8;
		}
		else
		{
			hsai_BlockA1.Instance->DR = outleft>>8;
			hsai_BlockA1.Instance->DR = outright>>8;
		}
	}
}
#endif

/**
 * Structure to hold configuration parameters
 */
typedef struct {
    /** 
     * @brief PLLI2SN Multiplicator
     */
    uint32_t PLLI2SN;
    /**
     * @brief PLLI2SQ Divisor
     */
    uint32_t PLLI2SQ;
    /**
     * @brief PLLI2SDivQ (PLLI2SR) Divisor
     */
    uint32_t PLLI2SDivQ;
    /**
     * @brief MCKDIV - Master Clock Divider from SAI peripheral
     */
    uint32_t MCKDIV;
} SAI_CLOCK_CONFIG_t;

/**
 * @brief   Set the mupliplicator and divisor settings structure for the PLLI2S and SAI2 peripherals
 *          according to the frequency selection. The output of divisor PLLM must be 1MHz.
 *
 * @param   frequencySelection  Selected frequency, this should be specified through a WM8994_FREQ_... define
 * @param   config              Struct in which the parameter values will be written
 */
void SetClockConfigurationParameter(uint8_t frequencySelection, SAI_CLOCK_CONFIG_t* config)
{
    config->PLLI2SN = 295;
    config->PLLI2SQ = 6;
    config->PLLI2SDivQ = 1;
    config->MCKDIV = 2;

    switch (frequencySelection)
    {
        case WM8994_FREQ_11_025K:
        case WM8994_FREQ_22_05K:
        case WM8994_FREQ_44_1K:
            config->PLLI2SN = 271;
            break;
        case WM8994_FREQ_8K:
        case WM8994_FREQ_12K:
        case WM8994_FREQ_16K:
        case WM8994_FREQ_24K:
        case WM8994_FREQ_32K:
        case WM8994_FREQ_48K:
        default:
            config->PLLI2SN = 295;
            break;
    }
    switch (frequencySelection)
    {
        case WM8994_FREQ_32K:
            config->PLLI2SQ = 3;
            break;
        case WM8994_FREQ_11_025K:
        case WM8994_FREQ_22_05K:
        case WM8994_FREQ_44_1K:
        case WM8994_FREQ_8K:
        case WM8994_FREQ_12K:
        case WM8994_FREQ_16K:
        case WM8994_FREQ_24K:
        case WM8994_FREQ_48K:
        default:
            config->PLLI2SQ = 6;
            break;
    }
    switch (frequencySelection)
    {
        case WM8994_FREQ_8K:
            config->MCKDIV = 12;
            SamplingRateHz = 8000.0f;
            break;
        case WM8994_FREQ_11_025K:
            config->MCKDIV = 8;
            SamplingRateHz = 11025.0f;
            break;
        case WM8994_FREQ_12K:
            config->MCKDIV = 8;
            SamplingRateHz = 12000.0f;
            break;
        case WM8994_FREQ_16K:
            config->MCKDIV = 6;
            SamplingRateHz = 16000.0f;
            break;
        case WM8994_FREQ_22_05K:
            config->MCKDIV = 4;
            SamplingRateHz = 22050.0f;
            break;
        case WM8994_FREQ_24K:
            config->MCKDIV = 4;
            SamplingRateHz = 24000.0f;
            break;
        case WM8994_FREQ_32K:
            config->MCKDIV = 6;
            SamplingRateHz = 32000.0f;
            break;
        case WM8994_FREQ_44_1K:
            config->MCKDIV = 2;
            SamplingRateHz = 44100.0f;
            break;
        case WM8994_FREQ_48K:
            config->MCKDIV = 2;
            SamplingRateHz = 48000.0f;
            break;
    }
    return;
}

/**
 * @brief   Changes multiplicator and divisor settings of the PLLI2S and SAI2 peripherals
 *
 * @param   selectedInput   Selected Input, this changes the amout of used slots
 * @param   config          Parameter values that should be configured
 *
 * @retval  Returns HAL_OK if the changes could be aplied in case of a time out HAL_TIMEOUT 
 *          will be returned
 * @remark  In case of a failure in configuring the SAI the system error handle will be called
 */
HAL_StatusTypeDef ReconfigureSAIClock(SAI_CLOCK_CONFIG_t* config, uint8_t selectedInput)
{
	uint32_t tickstart = 0;

	__HAL_RCC_PLLI2S_DISABLE();

	/* Get Start Tick*/
	tickstart = HAL_GetTick();

	/* Wait till PLLI2S is disabled */
	while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  != RESET)
	{
	  if((HAL_GetTick() - tickstart) > 100) // 100ms
	  {
		/* return in case of Timeout detected */
		return HAL_TIMEOUT;
	  }
	}

	__HAL_RCC_PLLI2S_CONFIG(config->PLLI2SN, 4, config->PLLI2SQ, 2);
	__HAL_RCC_PLLI2S_PLLSAICLKDIVQ_CONFIG(config->PLLI2SDivQ);
	__HAL_RCC_PLLI2S_ENABLE();

	/* Get Start Tick*/
	tickstart = HAL_GetTick();

	/* Wait till PLLI2S is ready */
	while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  == RESET)
	{
	  if((HAL_GetTick() - tickstart) > 100) // 100ms
	  {
		/* return in case of Timeout detected */
		return HAL_TIMEOUT;
	  }
	}

	int slots = (selectedInput & WM8994_INPUT_SLOT2) ? 4 : 2;
	hsai_BlockA1.FrameInit.FrameLength = 64*(slots/2);
	hsai_BlockA1.FrameInit.ActiveFrameLength = 32*(slots/2);
	hsai_BlockA1.SlotInit.SlotNumber = slots;
	hsai_BlockB1.FrameInit.FrameLength = 64*(slots/2);
	hsai_BlockB1.FrameInit.ActiveFrameLength = 32*(slots/2);
	hsai_BlockB1.SlotInit.SlotNumber = slots;

	hsai_BlockA1.Init.AudioFrequency = SAI_AUDIO_FREQUENCY_MCKDIV;
	hsai_BlockA1.Init.Mckdiv = config->MCKDIV;

	if (HAL_SAI_Init(&hsai_BlockA1) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_SAI_Init(&hsai_BlockB1) != HAL_OK)
	{
		Error_Handler();
	}

	return HAL_OK;
}

#ifdef AUDIO_DMA
/**
 * @brief Initializes the SAI and the audio codec for dma use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or line_in and/or mic_in defines
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param half_Callback     Callback for the half completion of transfer
 * @param full_Callback     Callback for the full completion of transfer
 */
void AudioInitDMA(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*half_Callback)(),
    void (*full_Callback)()
)
{
    ptrHalf_Callback = half_Callback;
    ptrFull_Callback = full_Callback;

    SAI_CLOCK_CONFIG_t config;
    SetClockConfigurationParameter(selectedFrequency, &config);
    ReconfigureSAIClock(&config, selectedInput);
    
    HAL_SAI_Transmit_DMA(&hsai_BlockA1, (uint8_t*)bufferTransmit, BUFFER_SIZE * 2);
    HAL_SAI_Receive_DMA(&hsai_BlockB1, (uint8_t*)bufferReceive, BUFFER_SIZE * 2);
    
    InitAudioCodec(&hi2c4, selectedFrequency, selectedInput);
}

#endif

#ifdef AUDIO_IT
/**
 * @brief Initialises the SAI and the audio codec for sample interrupt use
 *
 * @param selectedInput     Selected input, specified through WM8994_INPUT_... defines or line_in and/or mic_in defines
 * @param selectedFrequency Selected sample rate, specified through WM8994_FREQ_...K defines or hz..... defines
 * @param sample_Callback   Callback for an audio sample pair
 */
HAL_StatusTypeDef AudioInitIT(
    const uint8_t selectedFrequency,
    const uint8_t selectedInput,
    void (*sample_Callback)(uint32_t inLeft, uint32_t inRight, uint32_t* outLeft, uint32_t* outRight)
)
{
    ptrSample_Callback = sample_Callback;
    input = selectedInput;

    SAI_CLOCK_CONFIG_t config;
    SetClockConfigurationParameter(selectedFrequency, &config);
    ReconfigureSAIClock(&config, selectedInput);

    __HAL_LOCK(&hsai_BlockA1);
    __HAL_LOCK(&hsai_BlockB1);
  
    hsai_BlockA1.InterruptServiceRoutine = SAI_IT;
    hsai_BlockA1.Instance->DR = 0;
    hsai_BlockA1.Instance->DR = 0;
    if (selectedInput & WM8994_INPUT_SLOT2)
    {
    	hsai_BlockA1.Instance->DR = 0;
		hsai_BlockA1.Instance->DR = 0;
    }
    hsai_BlockB1.Instance->CR2 |= SAI_xCR2_FFLUSH_Msk;
  
    __HAL_SAI_ENABLE(&hsai_BlockB1);
    __HAL_SAI_ENABLE(&hsai_BlockA1);
    __HAL_SAI_ENABLE_IT(&hsai_BlockA1, SAI_IT_OVRUDR | SAI_IT_FREQ | SAI_IT_WCKCFG); //TODO maybe remove the other two
  
    __HAL_UNLOCK(&hsai_BlockA1);
    __HAL_UNLOCK(&hsai_BlockB1);

    InitAudioCodec(&hi2c4, selectedFrequency, selectedInput);

    return HAL_OK;
}

#endif

typedef struct BITVAL    // used in function prbs()
{
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    unsigned short b7:1, b8:1, b9:1, b10:1, b11:1, b12:1,b13:1;
    unsigned short dweebie:2; //Fills the 2 bit hole - bits 14-15
} bitval;

typedef union SHIFT_REG
{
    unsigned short regval;
    bitval bt;
} shift_reg;
int fb = 1;                        	    // feedback variable
shift_reg sreg = {0xFFFF};         	    // shift register

short prbs(void) 			     	    //gen pseudo-random sequence {-1,1}
{
    int prnseq;
    if(sreg.bt.b0)
	    prnseq = -NOISELEVEL;		    //scaled negative noise level
    else
	    prnseq = NOISELEVEL;		    //scaled positive noise level
    fb =(sreg.bt.b0)^(sreg.bt.b1);      //XOR bits 0,1
    fb^=(sreg.bt.b11)^(sreg.bt.b13);    //with bits 11,13 -> fb
    sreg.regval<<=1;
    sreg.bt.b0=fb;			    	    //close feedback path
    return prnseq;			   		    //return noise sequence value
}
