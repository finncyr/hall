// loop_intr.c 
#include "LabCode.h"

#ifdef LAB1_LOOP_INTR

volatile int32_t audio_chR=0;    
volatile int32_t audio_chL=0;   

void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight
)
{
    audio_chL = inLeft;
    audio_chR = inRight;

    //Process
        
    *outLeft = audio_chL;
    *outRight = audio_chR;
}

void Init()
{
    AudioInitIT(hz48000, line_in,
		Sample_Callback);
}

#endif
