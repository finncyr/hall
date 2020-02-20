#include "touch_button.h"

// define margins for display in pixels
static uint16_t display_bottom_margin = 30;
static uint16_t display_top_margin    = 30;
static uint16_t display_left_margin =  0;

//define displaying stuff
const char *header = "hall";
const char *buttontext = "Reverb";

uint16_t display_max_x, 
         display_max_y;

Circle_LCD button1;

uint8_t tsIsPressed;
uint8_t tsState;

void init_touch_button(){
    tsIsPressed = 0;
    tsState = 0;

    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
    BSP_LCD_SetLayerVisible(0, ENABLE);
    BSP_LCD_SelectLayer(0);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_DisplayOn();
    display_max_x =  BSP_LCD_GetXSize() - display_left_margin;
    display_max_y =  BSP_LCD_GetYSize() - display_bottom_margin- display_top_margin;

    button1.radius = 50;
    button1.xPos = (BSP_LCD_GetXSize() / 2) - button1.radius;
    button1.yPos = (BSP_LCD_GetYSize() / 2) - button1.radius;
}

void touch_update(){
    TS_StateTypeDef ts;
    BSP_TS_GetState(&ts);

    // discard any changes outside display borders
    if( (ts.touchX[0] >= BSP_LCD_GetXSize()) || (ts.touchY[0] >= BSP_LCD_GetYSize()) ){
        ts.touchX[0] = 0;
        ts.touchY[0] = 0;
        ts.touchDetected = 0;
    }
    //detect touch inputs
    if(ts.touchDetected){
        //detect if input is in borders of 2D-Rect around button1
        if( ts.touchX >= button1.xPos && ts.touchX <= button1.xPos + 2*button1.radius &&
            ts.touchY >= button1.yPos && ts.touchY <= button1.yPos + 2*button1.radius){
                tsIsPressed = (tsIsPressed) ? 0 : 1;
            }
    }
}

void display_button(){

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(display_left_margin,display_top_margin, display_max_x, display_max_y);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);

    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt(0, 8, (uint8_t *)header, CENTER_MODE);

    if(tsIsPressed){
        BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGREEN);
    }
    else{
        BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGRAY);
    }
    
    BSP_LCD_DrawCircle(button1.xPos, button1.yPos, button1.radius);

    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt( BSP_LCD_GetXSize()/2,BSP_LCD_GetYSize()/2, (uint8_t *)buttontext, CENTER_MODE);

}