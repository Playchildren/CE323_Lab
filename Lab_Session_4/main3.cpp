#include "mbed.h"
#include "stm32f413h_discovery_ts.h"
#include "stm32f413h_discovery_lcd.h"

TS_StateTypeDef TS_State = { 0 };

int main() {
    printf("Draw on the screen!\n");

    BSP_LCD_Init();										// ��ʼ��LCD 

    /* Touchscreen initialization */
    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) 
	{
        printf("BSP_TS_Init error\n");					// �����ʼ�����ɹ������� 
    }

    /* Clear the LCD */
    BSP_LCD_Clear(LCD_COLOR_WHITE);

    /* Set Touchscreen Demo1 description */
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);              // ���屳����ɫ
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 240);    // �������
    
    
    
     
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    
    int back_position[4] = {2,62,122,182};				// ���ñ���λ�� 
    for (int x: back_position){
        for (int y: back_position){
            BSP_LCD_FillRect(x,y,56,56);				// ��ͬ������ѭ������������ 
        }
    }
    
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_SetFont(&Font16);                           // �����С��ɫ 
    int i = -1;
    int font_H_position[4] ={25,85,145,205};			// Height 
    int font_W_position[4] ={-85,-25,35,95};			// Wide
    char* Keytable[] = {"1","2","3","F","4","5","6","E","7","8","9","D","A","0","B","C"};
    for (int v: font_H_position){
        for (int u: font_W_position){
            i = i+1;
            BSP_LCD_DisplayStringAt(u, v, (uint8_t *)Keytable[i], CENTER_MODE); 
        }
    }

    while (1) {
        BSP_TS_GetState(&TS_State);
        if(TS_State.touchDetected) {
            /* One or dual touch have been detected          */

            /* Get X and Y position of the first touch post calibrated */
            uint16_t x1 = TS_State.touchX[0];       // �������x���� 
            uint16_t y1 = TS_State.touchY[0];       // �������y���� 
    
            BSP_LCD_SetTextColor(LCD_COLOR_BLUE);   // ������ʾ��ɫ 
            BSP_LCD_FillCircle(x1, y1, 10);         // ָ���λ�úͰ뾶

            wait_ms(10);
        }
    }
}




