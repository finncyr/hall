#ifndef __TOUCH_BUTTON
#define __TOUCH_BUTTON

#include "STM32F769I-Discovery/stm32f769i_discovery_ts.h"
#include "arm_const_structs.h"

typedef struct Circle_LCD_info {
    uint16_t xPos;
    uint16_t yPos;
    uint16_t radius; 
}Circle_LCD;

void init_touch_button();

void touch_update();

void display_button();


#endif