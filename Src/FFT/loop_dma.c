// loop_dma.c
#include "LabCode.h"

#ifdef LAB5_LOOP_DMA

volatile bool bufferReady = false;
AudioDMABuffer_t* buffer;

void ProcessBuffer(AudioDMABuffer_t* buffer)
{
    for (int i = 0; i < BUFFER_SIZE; i+=2)
    {
        buffer->Output[i+1] = buffer->Input[i];
        buffer->Output[i] = buffer->Input[i+1];
    }
}

void Half_Callback(AudioDMABuffer_t* pingBuffer)
{
    buffer = pingBuffer;
    bufferReady = true;
}

void Full_Callback(AudioDMABuffer_t* pongBuffer)
{
    buffer = pongBuffer;
    bufferReady = true;
}

void Init()
{
    AudioInitDMA(WM8994_FREQ_48K, line_in,
                 Half_Callback,
                 Full_Callback);

    while (true) {
        if (bufferReady) {
            ProcessBuffer(buffer);
            bufferReady = false;
        }
    }
}

#endif
