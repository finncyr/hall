#include "LabCode.h"
#include "Audio/audio.h"
#include "FFT/fft.h"
#include "STM32F769I-Discovery/stm32f769i_discovery_lcd.h"
#include "batCave.h"

bool data_available = false;
bool processing_data = false;

int32_t value1, value2;
int32_t seperated_buf_index;
int32_t audio_chL[BUFFER_SIZE/2];
int32_t audio_chR[BUFFER_SIZE/2];
float32_t conv_resL[BUFFER_SIZE/2+ 37074 -1];
float32_t audio_chL_f[BUFFER_SIZE/2];
// define a pointer to an ARM FFT instance
arm_cfft_instance_f32* arm_cfft_instance_conv = NULL;

void combFilter(uint32_t *samples, uint32_t *output, int samplesLength, int delayInMilliSec, float32_t decayFactor, int sampleRate);

void ProcessBuffer()
{
	seperated_buf_index = 0;
	for (int n = 0; n < BUFFER_SIZE; n+=2)
	 {
		audio_chL[seperated_buf_index]= ProcessingBuffer.Input[n];
	    audio_chR[seperated_buf_index]= ProcessingBuffer.Input[n+1];
	    seperated_buf_index ++;
	 }

	//combFilter(audio_chL, audio_chL, BUFFER_SIZE/2, 10, 0.7, 48000);
	/*arm_cfft_radix4_init_f32(arm_cfft_instance_conv, 4096, 0, 1);
	arm_cfft_radix4_f32(arm_cfft_instance_conv, h);
	arm_cfft_radix4_f32(arm_cfft_instance_conv, audio_chL);
	 Complex Multiplication of the two input buffers in frequency domain
	arm_cmplx_mult_cmplx_f32(audio_chL, h, conv_resL, BUFFER_SIZE/2);
	Transform the multiplication output from frequency domain to time domain,
	     that gives the convolved output
	arm_cfft_radix4_init_f32(arm_cfft_instance_conv, 4096, 1, 1);
	arm_cfft_radix4_f32(arm_cfft_instance_conv, conv_resL);
	*/
	for(int i = 0; i<BUFFER_SIZE/2;i++){
		audio_chL_f[i] = (float32_t)audio_chL[i];
	}
	arm_conv_f32(audio_chL_f,BUFFER_SIZE/2,h,37074,conv_resL);

	 seperated_buf_index = 0;
	 for (int n = 0; n < BUFFER_SIZE; n+=2)
	 {
		 ProcessingBuffer.Output[n] = conv_resL[seperated_buf_index];
		 ProcessingBuffer.Output[n+1] = audio_chR[seperated_buf_index];
		 seperated_buf_index ++;
	 }

  if (processing_data == false)
  {
    Copy_To_FFT_Buffer(ProcessingBuffer.Input);
    data_available = true;
  }
  // circularly increment interrupt counter
  if (++interrupt_counter == CM)
  {
    interrupt_counter = 0;
  }
  cycles_btwn_irs[interrupt_counter] = 0;
}

void Init()
{//48kHz -> FS auch aendern
    AudioInitDMA(hz48000, line_in, ProcessBuffer, ProcessBuffer);
    arm_cfft_instance_conv = &arm_cfft_sR_f32_len4096;
}

uint32_t cycles_btwn_irs[CM] = {0};
uint16_t interrupt_counter = 0; //counter for the interrupts


void combFilter(uint32_t *samples, uint32_t *output, int samplesLength, int delayInMilliSec, float32_t decayFactor, int sampleRate){

    int delayOfSamples = delayInMilliSec * (sampleRate/1000);

	for(int i = 0; i < samplesLength; i++) output[i] = samples[i];

    for (int i = 0; i < samplesLength - delayOfSamples; i++){
        output[i+delayOfSamples] = (uint32_t)(output[i] * decayFactor);
    }
}
