// A kind of clever method used by tutor.
// Blink LED at 4 different rates and print on LCD display.

#include "mbed.h"
#include "C12832.h"

Timeout flipper;
Timeout flipper2;
Timeout flipper3;

float  rate = 2;

DigitalOut led1(p5);

void flip(){
	rate = 1.5;
}
void flip2(){
	rate = 1;
}
void flip3(){
	rate = 0.5;
}

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

int main(){
	led1 = 0;
	flipper.attach(&flip,4);
	flipper2.attach(&flip2,8);
	flipper3.attach(&flip3,12);
	
	while(1){
		if (led1 == 1){
			lcd.cls();
            lcd.locate(52, 10);
            lcd.printf("XXXX");
		}
		else if (led1 == 0){
			lcd.cls();
            lcd.locate(52, 10);
            lcd.printf("OOOO");
		}
	
	led1 = !led1;
	wait(rate);
	printf("The current rate is %f\n", rate);
	
	
	}
	
}
