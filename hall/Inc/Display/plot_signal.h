/**
 *****************************************************************************
 * @file    plot_signal.h
 * @brief   Plot signals on the display of the stm32f769i_discovery board
 * @author  Harald Elders-Boll
 ******************************************************************************
 *
 */

#ifndef __PLOT_SIGNAL
#define __PLOT_SIGNAL
#include "STM32F769I-Discovery/stm32f769i_discovery_lcd.h"
#include "arm_const_structs.h"


/**
 * @brief Initialize the signal plotter
 *
 */
void Init_Plot_Signal();
/**
 * @brief Plot the FFT of both channel taken as a complex signal
 *
 */
void Display_FFT();
/**
 * @brief Plot the FFTs of both channels
 *
 */
void Display_FFT2();
/**
 * @brief Plot one signals (left or right channel)
 *
 * @param channel     Select channel
 */
void Display_Signal(uint16_t channel);
/**
 * @brief Plot two signals (left and right channel)
 *
 */
void Display_Signal2();
/**
 * @brief Plot a signal on the display of the stm32f769i discovery board
 *
 * @param samples      Pointer to array of float32_t containing the input samples
 * @param num_samples  Number of samples
 * @param title        Title string
 * @param xmin         Minimum of x-axis
 * @param xmax         Maximum of x-axis
 * @param ymin         Minimum of y-axis
 * @param ymax         Maximum of y-axis
 * @param xdiv         Distance between two ticks on the x-axis, if set to zero ten equidistant ticks
 */
void Plot_Signal_Float(float32_t *samples, uint16_t num_samples, float32_t xmin, float32_t xmax, float32_t ymin, float32_t ymax, const char *title, float32_t xdiv);


/**
 * @brief Plot a 2 channel signal on the display of the stm32f769i discovery board
 *
 * @param samples      Pointer to array of float32_t containing the input samples
 * @param num_samples  Number of samples
 * @param title        Title string
 * @param xmin         Minimum of x-axis
 * @param xmax         Maximum of x-axis
 * @param ymin         Minimum of y-axis
 * @param ymax         Maximum of y-axis
 * @param xdiv         Distance between two ticks on the x-axis, if set to zero ten equidistant ticks
 */
void Plot_Signal2_Fast(float32_t *samples, uint16_t num_samples, float32_t xmin, float32_t xmax, float32_t ymin, float32_t ymax, const char *title, float32_t xdiv);

/**
 * @brief Plot a 2 channel signal on the display of the stm32f769i discovery board
 *
 * @param samples      Pointer to array of float32_t containing the input samples
 * @param num_samples  Number of samples
 * @param title        Title string
 * @param xmin         Minimum of x-axis
 * @param xmax         Maximum of x-axis
 * @param ymin         Minimum of y-axis
 * @param ymax         Maximum of y-axis
 * @param xdiv         Distance between two ticks on the x-axis, if set to zero ten equidistant ticks
 */
void Plot_Signal2_Float(float32_t *samples, uint16_t num_samples, float32_t xmin, float32_t xmax, float32_t ymin, float32_t ymax, const char *title, float32_t xdiv);

uint16_t display_x(float32_t xmin, float32_t x, float32_t xmax);
uint16_t display_y(float32_t ymin, float32_t y, float32_t ymax);

#endif /* __PLOT_SIGNAL */
