// My foolish way to achieve the function
// bilnk LED at 4 different rates and print on LCD display

#include "mbed.h"
#include "C12832.h"
Timeout flipper1;
Timeout flipper2;
Timeout flipper3;

DigitalOut led1(LED1);
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

void flip1(){
    printf("0.5 show is beginning\n");
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
        wait(0.5);
        
    }
}

void flip2(){
    printf("1.0 show is beginning\n");
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
        wait(1);
        
    }
}

void flip3(){
    printf("2.0 show is beginning\n");
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
    wait(5);
    printf("0.2 show is beginning\n");
    flipper1.attach(&flip1, 5);
    flipper2.attach(&flip2, 10);
    flipper3.attach(&flip3, 15);
    while(1){
        led1 = !led1;
        wait(0.2);
    }
}
