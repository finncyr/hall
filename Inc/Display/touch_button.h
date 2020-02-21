/**
 *****************************************************************************
 * @file    touch_button.h
 * @brief   Plots a usable touch button on the display of the
 *stm32f769i_discovery board
 * @author  Finn Cyriax
 ******************************************************************************
 *
 */

#ifndef __TOUCH_BUTTON
#define __TOUCH_BUTTON

#include "STM32F769I-Discovery/stm32f769i_discovery_ts.h"
#include "arm_const_structs.h"

/**
 * @brief Carries LCD-Circle Data
 * @details can be used to organize data needed for displaying a circle
 *
 */
typedef struct Circle_LCD_info {
    uint16_t xPos;
    uint16_t yPos;
    uint16_t radius;
} Circle_LCD;

/**
 * @brief Initialize the Display and TS
 *
 */
void init_touch_button();

/**
 * @brief Updates a global variable based on touch input
 *
 */
void touch_update();

/**
 * @brief Draws a button to click on TS with changing colors based on
 * touch_update()
 *
 */
void draw_button1();

#endif
