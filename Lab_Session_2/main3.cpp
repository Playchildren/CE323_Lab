#include "mbed.h"
#include "C12832.h"

Timeout flipper;
DigitalOut led1(LED1);
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

void flip(){
    printf("Game show is beginning\n");
    while(1){

        if(led1 == 1){
            lcd.cls();
            lcd.locate(52, 10);
            lcd.printf("XXXX");
        }
        else if(led1 == 0){
            lcd.cls();
            lcd.locate(52, 10);
            lcd.printf("OOOO");
        }
        
    led1 = !led1;
        wait(2);
        
    }
}

int main(){
    led1 = 1;
    flipper.attach(&flip, 5);
    while(1){
        led1 = !led1;
        wait(0.5);
    }
}
