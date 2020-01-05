#include "LabCode.h"
#include "Audio/audio.h"
#include "FFT/fft.h"
#include "STM32F769I-Discovery/stm32f769i_discovery_lcd.h"

bool data_available = false;
bool processing_data = false;

int32_t value1, value2;


void ProcessBuffer()
{
  for (int n = 0; n < BUFFER_SIZE; n+=2)
  {
    value1= ProcessingBuffer.Input[n];
    value2= ProcessingBuffer.Input[n+1];
    ProcessingBuffer.Output[n] = value1;
    ProcessingBuffer.Output[n+1] = value2;
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
}

uint32_t cycles_btwn_irs[CM] = {0};
uint16_t interrupt_counter = 0; //counter for the interrupts
