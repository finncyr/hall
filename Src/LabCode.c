#include "LabCode.h"
#include "Audio/audio.h"
#include "FFT/fft.h"
#include "STM32F769I-Discovery/stm32f769i_discovery_lcd.h"
//#include "batCave.h"
//#include "comb14.h"
//#include "batcave_256.h"
#include "batcave_512.h"
//#include "batcave_1024.h"
#include "stdlib.h"

bool data_available = false;
bool processing_data = false;

int32_t value1, value2;
int32_t seperated_buf_index;
int32_t audio_chL[BUFFER_SIZE / 2];
int32_t audio_chR[BUFFER_SIZE / 2];
float32_t conv_resL[BUFFER_SIZE / 2 + 37074 - 1];
float32_t audio_chL_f[BUFFER_SIZE / 2];
// define a pointer to an ARM FFT instance
// arm_cfft_instance_f32* arm_cfft_instance_conv = NULL;

float32_t *pState;

void combFilter(uint32_t *samples, uint32_t *output, int samplesLength,
                int delayInMilliSec, float32_t decayFactor, int sampleRate);
uint16_t numTaps = N;

volatile uint8_t *copy_tsIsPressed;

void ProcessBuffer() {
  // seperate samples
  seperated_buf_index = 0;
  for (int n = 0; n < BUFFER_SIZE; n += 2) {
    audio_chL[seperated_buf_index] = ProcessingBuffer.Input[n];
    audio_chR[seperated_buf_index] = ProcessingBuffer.Input[n + 1];
    seperated_buf_index++;
  }

  for (int i = 0; i < BUFFER_SIZE / 2; i++) {
    audio_chL_f[i] = (float32_t)audio_chL[i];
    // audio_chL[i] = (int32_t)audio_chL[i];
  }

  if (*copy_tsIsPressed) {
    arm_fir_instance_f32 S = {numTaps, pState, h};

    arm_fir_f32(&S, audio_chL_f, conv_resL, BUFFER_SIZE / 2);

    // reassemble buffer
    seperated_buf_index = 0;
    for (int n = 0; n < BUFFER_SIZE; n += 2) {
      ProcessingBuffer.Output[n] =
          (int32_t)(0.28 * conv_resL[seperated_buf_index]);
      ProcessingBuffer.Output[n + 1] = audio_chR[seperated_buf_index];
      seperated_buf_index++;
    }

  } else {
    // reassemble buffer
    seperated_buf_index = 0;
    for (int n = 0; n < BUFFER_SIZE; n += 2) {
      ProcessingBuffer.Output[n] = audio_chL[seperated_buf_index];
      ProcessingBuffer.Output[n + 1] = audio_chR[seperated_buf_index];
      seperated_buf_index++;
    }
  }

  if (processing_data == false) {
    Copy_To_FFT_Buffer(ProcessingBuffer.Input);
    data_available = true;
  }
  // circularly increment interrupt counter
  if (++interrupt_counter == CM) {
    interrupt_counter = 0;
  }
  cycles_btwn_irs[interrupt_counter] = 0;
}

void Init(uint8_t *tsIsPressed) { // 48kHz -> FS auch aendern
  AudioInitDMA(hz48000, line_in, ProcessBuffer, ProcessBuffer);
  // arm_cfft_instance_conv = &arm_cfft_sR_f32_len4096;
  pState =
      (float32_t *)calloc(numTaps + BUFFER_SIZE / 2 - 1, sizeof(float32_t));

  copy_tsIsPressed = tsIsPressed;
}

uint32_t cycles_btwn_irs[CM] = {0};
uint16_t interrupt_counter = 0; // counter for the interrupts

void combFilter(uint32_t *samples, uint32_t *output, int samplesLength,
                int delayInMilliSec, float32_t decayFactor, int sampleRate) {

  int delayOfSamples = delayInMilliSec * (sampleRate / 1000);

  for (int i = 0; i < samplesLength; i++)
    output[i] = samples[i];

  for (int i = 0; i < samplesLength - delayOfSamples; i++) {
    output[i + delayOfSamples] = (uint32_t)(output[i] * decayFactor);
  }
}
