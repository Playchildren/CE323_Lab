#include "mbed.h"
#include "stm32f413h_discovery_ts.h"
#include "stm32f413h_discovery_lcd.h"
#include "C12832.h"
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
TS_StateTypeDef TS_State = { 0 };

int main() {
    printf("Draw on the screen!\n");

    BSP_LCD_Init();										// Initializes the LCD

    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) 
	{
        printf("BSP_TS_Init error\n");					// If initialization is unsuccessful, report an error
    }

    BSP_LCD_Clear(LCD_COLOR_WHITE);		                // Clear the LCD		

    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);              // Set Touchscreen description
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 240);    // The width of the background
    
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);              // Set Rectangle description
    int back_position[4] = {2,62,122,182};				// Set the square background position
    for (int x: back_position){
        for (int y: back_position){
            BSP_LCD_FillRect(x,y,56,56);}
    }

    BSP_LCD_SetTextColor(LCD_COLOR_RED);                // Set Texts description
    BSP_LCD_SetFont(&Font16);                           // Font size color
    int i = 0;
    int font_H_position[4] ={25,85,145,205};			// Height 
    int font_W_position[4] ={-85,-25,35,95};			// Wide
    char* Keytable[] = {"1","2","3","F","4","5","6","E","7","8","9","D","A","0","B","C"};
    for (int v: font_H_position){
        for (int u: font_W_position){
            BSP_LCD_DisplayStringAt(u, v, (uint8_t *)Keytable[i], CENTER_MODE); 
            i = i+1;}
    }
	int length = 0;										// The current digit 
	char ch[4]  = {'_','_','_','_'};					// Saves the currently entered four digits
	char ch2[4] = {'_','_','_','_'};					// Validation for the second input
    while (1) {
        BSP_TS_GetState(&TS_State);
        if(TS_State.touchDetected) {					// If the screen is detected being pressed
            if (length<0)length = 0;					// Since the input is 0-4 bits, the input is range-limited
            if (length>4)length = 4;
            /* Get X and Y position of the first touch post calibrated */
            uint16_t x1 = TS_State.touchX[0];
            uint16_t y1 = TS_State.touchY[0];

            if (int(x1)>2&&int(x1)<58&&int(y1)>2&&int(y1)<62){				// When the '1' on the screen is pressed
                ch[length] = '1'; length = length + 1;}						// Record '1' to 'ch', total bit length +1
                
            else if (int(x1)>62&&int(x1)<118&&int(y1)>2&&int(y1)<62){		// When the '2' on the screen is pressed
                ch[length] = '2'; length = length + 1;}
                
            else if (int(x1)>122&&int(x1)<178&&int(y1)>2&&int(y1)<62){		// When the '3' on the screen is pressed
                ch[length] = '3'; length = length + 1;}
                
            else if (int(x1)>2&&int(x1)<58&&int(y1)>62&&int(y1)<118){		// When the '4' on the screen is pressed
                ch[length] = '4'; length = length + 1;}
                
            else if (int(x1)>62&&int(x1)<118&&int(y1)>62&&int(y1)<118){		// When the '5' on the screen is pressed
                ch[length] = '5'; length = length + 1;}
                
            else if (int(x1)>122&&int(x1)<178&&int(y1)>62&&int(y1)<118){	// When the '6' on the screen is pressed
                ch[length] = '6'; length = length + 1;}
                
            else if (int(x1)>2&&int(x1)<58&&int(y1)>112&&int(y1)<178){		// When the '7' on the screen is pressed
                ch[length] = '7'; length = length + 1;}
                
            else if (int(x1)>62&&int(x1)<118&&int(y1)>112&&int(y1)<178){	// When the '8' on the screen is pressed
                ch[length] = '8'; length = length + 1;}
                
            else if (int(x1)>122&&int(x1)<178&&int(y1)>112&&int(y1)<178){	// When the '9' on the screen is pressed
                ch[length] = '9'; length = length + 1;}
                
            else if (int(x1)>62&&int(x1)<118&&int(y1)>182&&int(y1)<238){	// When the '0' on the screen is pressed
                ch[length] = '0'; length = length + 1;}
                
            if (int(x1)>182&&int(x1)<238&&int(y1)>182&&int(y1)<238){ 		// When the 'C' on the screen is pressed
                ch[length - 1] = '_';										// The previous bit is replaced to '_'
                length = length - 1;										// Total bit length -1
            }

            if (ch[3] != '_'){												//Print 'Press B to Set' on the first line 
                lcd.locate(2,5);											//if the fourth bit saved is detected.
                lcd.printf("Press B to set");
            }
            else{
                lcd.locate(2,5);
                lcd.printf("              ");  
            }
            if (int(x1)>122&&int(x1)<178&&int(y1)>182&&int(y1)<238){		// When the 'B' on the screen is pressed
                if(ch[0]==ch2[0]&&ch[1]==ch2[1]&&ch[2]==ch2[2]&&ch[3]==ch2[3]){
                	/*It will be executed after each press of B, 
					but the condition is not met after the first press, 
					and the decision after the second input is waited */
                    lcd.locate(2,5);										// If the second input is equal to the first, the output is 'CE323A1'
                    lcd.printf("CE323 A1        ");
                }
                else{
                    lcd.locate(2,5);
                    lcd.printf("                ");
                }
                for(int u=0;u<4;u++){
                    ch2[u] = ch[u];			// When B is pressed, the elements in 'ch' are saved to 'ch2' and the 'ch' is reset. 
                    ch[u] = '_';			// When B is pressed next time, Compare new 'CH' and 'ch2'.
                }
                length = 0;
            }

            lcd.locate(2,15);												// Print the information currently entered on the second line
            lcd.printf("Code:%c %c %c %c",ch[0],ch[1],ch[2],ch[3]);
            wait_ms(200);													// If it is too small, a single touch will result in multiple inputs, 
        }																	// If it is too large, multiple touches will result in only one input
    }
}
