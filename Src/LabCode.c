#include "LabCode.h"
#ifdef LABCODE

//When using line_in as input, in the inLeft and inRight parameters are the values of the
//line input. Then using an other parameter the other channel is passed through inLeft/inRight
//When also line_in is specified then the value are in *outLeft, *outRight.

void Sample_Callback(
    uint32_t inLeft,
    uint32_t inRight,
    uint32_t* outLeft,
    uint32_t* outRight
)
{
    *outLeft = inLeft;
    *outRight = inRight;
}

void Init()
{
    AudioInitIT(WM8994_FREQ_48K, line_in,
        Sample_Callback);
}

#endif

uint32_t cycles_btwn_irs[CM] = {0};
uint16_t interrupt_counter = 0; //counter for the interrupts
