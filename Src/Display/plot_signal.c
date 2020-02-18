/**
 *****************************************************************************
 * @file    plot_signal.c
 * @brief   Plot signal on the display of the stm32f769i_discovery board
 * @author  Harald Elders-Boll
 ******************************************************************************
 *
 */
#include "Display/plot_signal.h"
#include "FFT/fft.h"
float32_t display_buffer[FFT_SIZE]; // display buffer
// define title strings for plots
const char *fft_title = "Magnitude of FFT";
const char *plot_title = "Time signal";
// define margins for display in pixels
static uint16_t display_bottom_margin = 30;
static uint16_t display_top_margin = 30;
static uint16_t display_left_margin = 0;
// variables for storing the size of the display in pixels
uint16_t display_max_x;
uint16_t display_max_y;

void Init_Plot_Signal() {
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  BSP_LCD_SetLayerVisible(0, ENABLE);
  BSP_LCD_SelectLayer(0);
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_DisplayOn();
  display_max_x = BSP_LCD_GetXSize() - display_left_margin;
  display_max_y =
      BSP_LCD_GetYSize() - display_bottom_margin - display_top_margin;
}

void Display_FFT() {
  uint16_t max_index, n;
  float32_t Sreal, Simag;
  float32_t ymax = 0;
  // Compute the magnitude of each elements of a complex data vector
  // First argument is the input buffer of 2*N interleaved float values
  // Second argument is the display_buffer buffer of N float values
  // Third argument is N
  for (n = 0; n < FFT_SIZE / 2; n += 2) {
    Sreal = fft_buffer[2 * n];
    Simag = fft_buffer[2 * n + 1];
    arm_sqrt_f32(Sreal * Sreal + Simag * Simag, &display_buffer[n]);
    if (display_buffer[n] > ymax) {
      ymax = display_buffer[n];
    }
  }
  // Plot the magnitude of the FFT, plot only the FFT values from f=0 to f=r/2,
  // where r is the sampling rate
  Plot_Signal_Float(display_buffer, FFT_SIZE / 2, 0.0, SamplingRateHz / 2.0,
                    0.0, ymax, fft_title, 1000.0f);
}

void Display_FFT2() {
  uint32_t max_index;
  float32_t S1_real, S1_imag, S2_real, S2_imag;
  float32_t ymax;
  uint16_t n;
  // Now let's separate the FFTs of the first and second channel!
  //
  // The FFT of the real part of the time domain signal has an
  // real part that is even and an imaginary part that is odd.
  // The FFT the imaginary part of the time domain signal has an
  // real part that is odd and an imaginary part that is even.
  //
  // Lets start with real and imaginary part of the FFT at frequency index k=0
  // We can obtain the magnitude of them by the following lines
  display_buffer[0] = fft_buffer[0] < 0.0f ? -fft_buffer[0] : fft_buffer[0];
  display_buffer[1] = fft_buffer[1] < 0.0f ? -fft_buffer[1] : fft_buffer[1];
  // However we choose to ignore the DC component of each channel
  // display_buffer[0] = 0.0f;
  // display_buffer[1] = 0.0f;
  ymax = display_buffer[0] > display_buffer[1] ? display_buffer[0]
                                               : display_buffer[1];
  for (n = 2; n < FFT_SIZE; n += 2) {
    // imaginary part of FFT of first channel = odd part of imaginary part
    S1_imag = (fft_buffer[n + 1] - fft_buffer[BUFFER_SIZE - n + 1]) / 2.0f;
    // imaginary part of FFT of second channel = - odd part of real part
    S2_imag = -(fft_buffer[n] - fft_buffer[BUFFER_SIZE - n]) / 2.0f;
    // real part of FFT of first channel = even part of real part
    S1_real = (fft_buffer[n] + fft_buffer[BUFFER_SIZE - n]) / 2.0f;
    // real part of FFT of second channel = even part of imaginary part
    S2_real = (fft_buffer[n + 1] + fft_buffer[BUFFER_SIZE - n + 1]) / 2.0f;
    // magnitude of FFT of first channel
    arm_sqrt_f32(S1_real * S1_real + S1_imag * S1_imag, &display_buffer[n]);
    // magnitude of FFT of first channel
    arm_sqrt_f32(S2_real * S2_real + S2_imag * S2_imag, &display_buffer[n + 1]);
    if (display_buffer[n] > ymax) {
      ymax = display_buffer[n];
    }
    if (display_buffer[n + 1] > ymax) {
      ymax = display_buffer[n + 1];
    }
  } // end for
  // Plot the magnitude of the FFT, plot only the FFT values from f=0 to f=r/2,
  // where r is the sampling rate
  Plot_Signal2_Float(display_buffer, FFT_SIZE, 0.0, SamplingRateHz / 2.0, 0.0,
                     ymax, fft_title, 1000.0f);
}

void Display_Signal(uint16_t channel) {
  uint32_t max_index, n;
  float32_t ymax, ymin, xmax;
  uint16_t channelselect = channel % 2;
  for (n = 0; n < FFT_SIZE; n++) {
    display_buffer[n] = fft_buffer[2 * n + channelselect];
  }
  // calculate maximum signal value
  arm_max_f32(display_buffer, FFT_SIZE, &ymax, &max_index);
  // calculate maximum signal value
  arm_min_f32(display_buffer, FFT_SIZE, &ymin, &max_index);
  xmax = ((float32_t)FFT_SIZE) / (float32_t)SamplingRateHz;
  // Plot only one channel, xmin=0.0, xmax, xdiv= xmax*0.1
  Plot_Signal_Float(display_buffer, FFT_SIZE, 0.0, xmax, ymin, ymax,
                    "Time signal", xmax * 0.1f);
}

void Display_Signal2() {
  uint32_t max_index, n;
  float32_t ymax, ymin, xmax;
  // calculate maximum signal value
  arm_max_f32(fft_buffer, BUFFER_SIZE, &ymax, &max_index);
  // calculate maximum signal value
  arm_min_f32(fft_buffer, BUFFER_SIZE, &ymin, &max_index);
  xmax = ((float32_t)FFT_SIZE) / (float32_t)SamplingRateHz;
  // Plot two channels, xmin=0.0, xmax, xdiv= xmax*0.1
  Plot_Signal2_Float(fft_buffer, BUFFER_SIZE, 0.0, xmax, ymin, ymax,
                     "Time signal", xmax * 0.1f);
}

void Plot_Signal_Fast(float32_t *samples, uint16_t num_samples, float32_t xmin,
                      float32_t xmax, float32_t ymin, float32_t ymax,
                      const char *title, float32_t xdiv) {
  char s[30];
  uint16_t previous_sample, i, k;
  float32_t y_xaxis = 0.0f;
  float32_t xtickval;
  if (ymin > 0.0f) {
    y_xaxis = ymin; // draw x-axis at y=ymin
  } else if (ymax < 0.0f) {
    y_xaxis = ymax; // draw x-axis at y=ymax
  }
  // clear complete display and use white color for background
  // ===========================
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_FillRect(display_left_margin, display_top_margin, display_max_x,
                   display_max_y);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  // display title
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(0, 8, (uint8_t *)title, CENTER_MODE);
  // display xmin
  snprintf(s, 15, "xmin=%-6f", xmin);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin +
                              display_bottom_margin - 14,
                          (uint8_t *)s, LEFT_MODE);
  // display xmax
  snprintf(s, 15, "xmax=%-6f", xmax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(
      0, display_max_y + display_top_margin + display_bottom_margin - 14,
      (uint8_t *)s, RIGHT_MODE);
  // display ymin
  snprintf(s, 15, "ymin=%-6f", ymin);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin, (uint8_t *)s,
                          LEFT_MODE);
  // display ymax
  snprintf(s, 15, "ymax=%-6f", ymax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin, 10, (uint8_t *)s, LEFT_MODE);
  // convert y-values to display y values ======================================
  // display_top_margin + display_max_y -
  // (uint16_t)((y-ymin)/(ymax-ymin)*display_max_y) compute y-ymin vectorized
  // in-place using ARM CMSIS function arm_offset_f32 (float32_t *pSrc,
  // float32_t offset, float32_t *pDst, uint32_t blockSize)
  arm_offset_f32(samples, -ymin, samples, num_samples);
  // multiply with -display_max_y/(ymax-ymin) in-place vectorized using ARM
  // CMSIS function arm_scale_f32 (float32_t *pSrc, float32_t scale, float32_t
  // *pDst, uint32_t blockSize)
  arm_scale_f32(samples, -display_max_y / (ymax - ymin), samples, num_samples);
  // add display_top_margin + display_max_y vectorized in-place using ARM CMSIS
  // function arm_offset_f32 (float32_t *pSrc, float32_t offset, float32_t
  // *pDst, uint32_t blockSize)
  arm_offset_f32(samples, (float32_t)(display_top_margin + display_max_y),
                 samples, num_samples);
  // draw x-axis
  // =========================================================================
  // use blue color
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_DrawLine(display_x(xmin, 0, xmax), display_y(ymin, y_xaxis, ymax),
                   display_x(xmin, xmax, xmax), display_y(ymin, y_xaxis, ymax));
  for (xtickval = xmin; xtickval <= xmax; xtickval += xdiv) {
    // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1) and
    // (X2, Y2),
    //                                   where (0,0) is upper, left of display
    BSP_LCD_DrawLine(
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) - 2,
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) + 2);
  }
  // plot the samples
  // =====================================================================
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  if (num_samples < display_max_x) {
    for (i = 1; i < num_samples; i++) {
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 1, num_samples),
                       (uint16_t)samples[i - 1], display_x(0, i, num_samples),
                       (uint16_t)samples[i]);
    }
  } else {
    previous_sample = (uint16_t)samples[0];
    for (i = 1; i < display_max_x; i++) {
      k = (num_samples * i) / display_max_x;
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample,
                       i + display_left_margin, (uint16_t)samples[k]);
      previous_sample = (uint16_t)samples[k];
    }
  }
}

void Plot_Signal_Float(float32_t *samples, uint16_t num_samples, float32_t xmin,
                       float32_t xmax, float32_t ymin, float32_t ymax,
                       const char *title, float32_t xdiv) {
  char s[30];
  uint16_t previous_sample, sample, i, k;
  float32_t y_xaxis = 0.0f;
  float32_t xtickval;
  if (ymin > 0.0f) {
    y_xaxis = ymin; // draw x-axis at y=ymin
  } else if (ymax < 0.0f) {
    y_xaxis = ymax; // draw x-axis at y=ymax
  }
  // clear complete display and use white color for background
  // ===========================
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_FillRect(display_left_margin, display_top_margin, display_max_x,
                   display_max_y);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  // display title
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(0, 8, (uint8_t *)title, CENTER_MODE);
  // display xmin
  snprintf(s, 15, "xmin=%-6f", xmin);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin +
                              display_bottom_margin - 14,
                          (uint8_t *)s, LEFT_MODE);
  // display xmax
  snprintf(s, 15, "xmax=%-6f", xmax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(
      0, display_max_y + display_top_margin + display_bottom_margin - 14,
      (uint8_t *)s, RIGHT_MODE);
  // display ymin
  snprintf(s, 15, "ymin=%-6f", ymin);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin, (uint8_t *)s,
                          LEFT_MODE);
  // display ymax
  snprintf(s, 15, "ymax=%-6f", ymax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin, 10, (uint8_t *)s, LEFT_MODE);
  // draw x-axis
  // =========================================================================
  // use blue color
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_DrawLine(display_x(xmin, 0, xmax), display_y(ymin, y_xaxis, ymax),
                   display_x(xmin, xmax, xmax), display_y(ymin, y_xaxis, ymax));
  for (xtickval = xmin; xtickval <= xmax; xtickval += xdiv) {
    // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1) and
    // (X2, Y2),
    //                                   where (0,0) is upper, left of display
    BSP_LCD_DrawLine(
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) - 2,
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) + 2);
  }
  // plot the samples
  // =====================================================================
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  if (num_samples < display_max_x) {
    previous_sample =
        display_top_margin + display_max_y -
        (uint16_t)((samples[0] - ymin) / (ymax - ymin) * display_max_y);
    for (i = 2; i < num_samples; i += 2) {
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[i] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 2, num_samples), previous_sample,
                       display_x(0, i, num_samples), sample);
      previous_sample = sample;
    }
  } else {
    previous_sample = (uint16_t)samples[0];
    for (i = 1; i < display_max_x; i++) {
      k = (num_samples * i) / display_max_x;
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[k] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample,
                       i + display_left_margin, sample);
      previous_sample = sample;
    }
  }
}

void Plot_Signal2_Fast(float32_t *samples, uint16_t num_samples, float32_t xmin,
                       float32_t xmax, float32_t ymin, float32_t ymax,
                       const char *title, float32_t xdiv) {
  char s[30];
  uint16_t previous_sample_1, previous_sample_2, i, k;
  float32_t y_xaxis = 0.0f;
  float32_t xtickval;
  if (ymin > 0.0f) {
    y_xaxis = ymin; // draw x-axis at y=ymin
  } else if (ymax < 0.0f) {
    y_xaxis = ymax; // draw x-axis at y=ymax
  }
  // clear complete display and use white color for background
  // ===========================
  // BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_FillRect(display_left_margin, display_top_margin, display_max_x,
                   display_max_y);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  // display title
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(0, 8, (uint8_t *)title, CENTER_MODE);
  // display xmin
  snprintf(s, 15, "xmin=%-6f", xmin);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin +
                              display_bottom_margin - 14,
                          (uint8_t *)s, LEFT_MODE);
  // display xmax
  snprintf(s, 15, "xmax=%-6f", xmax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(
      0, display_max_y + display_top_margin + display_bottom_margin - 14,
      (uint8_t *)s, RIGHT_MODE);
  // display ymin
  snprintf(s, 15, "ymin=%-6f", ymin);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin, (uint8_t *)s,
                          LEFT_MODE);
  // display ymax
  snprintf(s, 15, "ymax=%-6f", ymax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin, 10, (uint8_t *)s, LEFT_MODE);
  // convert y-values to display y values ======================================
  // display_y = top_margin + display_max_y -
  // (uint16_t)((y-ymin)/(ymax-ymin)*display_max_y) compute y-ymin vectorized
  // in-place using ARM CMSIS function arm_offset_f32 (float32_t *pSrc,
  // float32_t offset, float32_t *pDst, uint32_t blockSize)
  arm_offset_f32(samples, -ymin, samples, num_samples);
  // multiply with -display_max_y/(ymax-ymin) in-place vectorized using ARM
  // CMSIS function arm_scale_f32 (float32_t *pSrc, float32_t scale, float32_t
  // *pDst, uint32_t blockSize)
  arm_scale_f32(samples, -display_max_y / (ymax - ymin), samples, num_samples);
  // add display_top_margin + display_max_y vectorized in-place using ARM CMSIS
  // function arm_offset_f32 (float32_t *pSrc, float32_t offset, float32_t
  // *pDst, uint32_t blockSize)
  arm_offset_f32(samples, (float32_t)(display_top_margin + display_max_y),
                 samples, num_samples);
  // draw x-axis
  // =========================================================================
  // use blue color
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_DrawLine(display_x(xmin, 0.0f, xmax), display_y(ymin, y_xaxis, ymax),
                   display_x(xmin, xmax, xmax), display_y(ymin, y_xaxis, ymax));
  for (xtickval = xmin; xtickval <= xmax; xtickval += xdiv) {
    // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1) and
    // (X2, Y2),
    //                                   where (0,0) is upper, left of display
    BSP_LCD_DrawLine(
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) - 2,
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) + 2);
  }
  // plot the samples
  // =====================================================================
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  if (num_samples / 2 < display_max_x) {
    // set the (text) color for the first plot
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    for (i = 2; i < num_samples; i += 2) {
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 2, num_samples),
                       (uint16_t)samples[i - 2], display_x(0, i, num_samples),
                       (uint16_t)samples[i]);
    }
    // set the (text) color for the second plot
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    for (i = 3; i < num_samples; i += 2) {
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 3, num_samples),
                       (uint16_t)samples[i - 2],
                       display_x(0, i - 1, num_samples), (uint16_t)samples[i]);
    }
  } else {
    previous_sample_1 = (uint16_t)samples[0];
    previous_sample_2 = (uint16_t)samples[1];
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    for (i = 1; i < display_max_x; i++) {
      k = 2 * ((num_samples / 2 * i) / display_max_x);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample_1,
                       i + display_left_margin, (uint16_t)samples[k]);
      previous_sample_1 = (uint16_t)samples[k];
    }
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    for (i = 1; i < display_max_x; i++) {
      k = 2 * ((num_samples / 2 * i) / display_max_x) + 1;
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample_2,
                       i + display_left_margin, (uint16_t)samples[k]);
      previous_sample_2 = (uint16_t)samples[k];
    }
  }
}

void Plot_Signal2_Float(float32_t *samples, uint16_t num_samples,
                        float32_t xmin, float32_t xmax, float32_t ymin,
                        float32_t ymax, const char *title, float32_t xdiv) {
  char s[30];
  uint16_t previous_sample_1, previous_sample_2, i, k, sample;
  float32_t y_xaxis = 0.0f;
  float32_t xtickval;
  if (ymin > 0.0f) {
    y_xaxis = ymin; // draw x-axis at y=ymin
  } else if (ymax < 0.0f) {
    y_xaxis = ymax; // draw x-axis at y=ymax
  }
  // clear complete display and use white color for background
  // ===========================
  // BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_FillRect(display_left_margin, display_top_margin, display_max_x,
                   display_max_y);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  // display title
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(0, 8, (uint8_t *)title, CENTER_MODE);
  // display xmin
  snprintf(s, 15, "xmin=%-6f", xmin);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin +
                              display_bottom_margin - 14,
                          (uint8_t *)s, LEFT_MODE);
  // display xmax
  snprintf(s, 15, "xmax=%-6f", xmax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(
      0, display_max_y + display_top_margin + display_bottom_margin - 14,
      (uint8_t *)s, RIGHT_MODE);
  // display ymin
  snprintf(s, 15, "ymin=%-6f", ymin);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin,
                          display_max_y + display_top_margin, (uint8_t *)s,
                          LEFT_MODE);
  // display ymax
  snprintf(s, 15, "ymax=%-6f", ymax);
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_DisplayStringAt(display_left_margin, 10, (uint8_t *)s, LEFT_MODE);
  // draw x-axis
  // =========================================================================
  // use blue color
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_DrawLine(display_x(xmin, 0.0f, xmax), display_y(ymin, y_xaxis, ymax),
                   display_x(xmin, xmax, xmax), display_y(ymin, y_xaxis, ymax));
  for (xtickval = xmin; xtickval <= xmax; xtickval += xdiv) {
    // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1) and
    // (X2, Y2),
    //                                   where (0,0) is upper, left of display
    BSP_LCD_DrawLine(
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) - 2,
        display_x(xmin, xtickval, xmax), display_y(ymin, y_xaxis, ymax) + 2);
  }
  // plot the samples
  // =====================================================================
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  if (num_samples / 2 < display_max_x) {
    // set the (text) color for the first plot
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    previous_sample_1 =
        display_top_margin + display_max_y -
        (uint16_t)((samples[0] - ymin) / (ymax - ymin) * display_max_y);
    for (i = 2; i < num_samples; i += 2) {
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[i] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 2, num_samples), previous_sample_1,
                       display_x(0, i, num_samples), sample);
      previous_sample_1 = sample;
    }
    // set the (text) color for the second plot
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    previous_sample_1 =
        display_top_margin + display_max_y -
        (uint16_t)((samples[0] - ymin) / (ymax - ymin) * display_max_y);
    for (i = 3; i < num_samples; i += 2) {
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[i] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(display_x(0, i - 3, num_samples), previous_sample_1,
                       display_x(0, i - 1, num_samples), sample);
      previous_sample_1 = sample;
    }
  } else {
    previous_sample_1 = (uint16_t)samples[0];
    previous_sample_2 = (uint16_t)samples[1];
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    for (i = 1; i < display_max_x; i++) {
      k = 2 * ((num_samples / 2 * i) / display_max_x);
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[k] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample_1,
                       i + display_left_margin, sample);
      previous_sample_1 = sample;
    }
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    for (i = 1; i < display_max_x; i++) {
      k = 2 * ((num_samples / 2 * i) / display_max_x) + 1;
      sample = display_top_margin + display_max_y -
               (uint16_t)((samples[k] - ymin) / (ymax - ymin) * display_max_y);
      // BSP_LCD_DrawLine(X1, Y1, X2, Y2): Draw line between to points (X1,Y1)
      // and (X2, Y2),
      //                                   where (0,0) is upper, left of display
      BSP_LCD_DrawLine(i - 1 + display_left_margin, previous_sample_2,
                       i + display_left_margin, sample);
      previous_sample_2 = sample;
    }
  }
}

uint16_t display_x(float32_t xmin, float32_t x, float32_t xmax) {
  return (uint16_t)((x - xmin) / (xmax - xmin) * display_max_x) +
         display_left_margin;
}

uint16_t display_y(float32_t ymin, float32_t y, float32_t ymax) {
  return display_top_margin + display_max_y -
         (uint16_t)((y - ymin) / (ymax - ymin) * display_max_y);
}
