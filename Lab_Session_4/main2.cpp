#include "mbed.h"
#include "stm32f413h_discovery_ts.h"
#include "stm32f413h_discovery_lcd.h"

TS_StateTypeDef TS_State = { 0 };

int main() {
    printf("Draw on the screen!\n");

    BSP_LCD_Init();										// 初始化LCD 

    /* Touchscreen initialization */
    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) 
	{
        printf("BSP_TS_Init error\n");					// 如果初始化不成功，报错 
    }

    /* Clear the LCD */
    BSP_LCD_Clear(LCD_COLOR_WHITE);

    /* Set Touchscreen Demo1 description */
    BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);             // 整体背景颜色
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 240);    // 背景宽度
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);              // 字体颜色
    BSP_LCD_SetBackColor(LCD_COLOR_GREEN);              // 字体背景颜色
    BSP_LCD_SetFont(&Font16);                           // 字体大小
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)"Touch the screen", CENTER_MODE); 
    // 开始写字的高度

    while (1) {
        BSP_TS_GetState(&TS_State);
        if(TS_State.touchDetected) {
            /* One or dual touch have been detected          */

            /* Get X and Y position of the first touch post calibrated */
            uint16_t x1 = TS_State.touchX[0];       // 检测输入的x坐标 
            uint16_t y1 = TS_State.touchY[0];       // 检测输入的y坐标 
    
            BSP_LCD_SetTextColor(LCD_COLOR_BLUE);   // 定义显示颜色 
            BSP_LCD_FillCircle(x1, y1, 10);         // 指针的位置和半径

            wait_ms(10);
        }
    }
}




