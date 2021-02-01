// use switch to control the blink of led
// when switch on, led on, switch off, led off

#include "mbed.h"
#include "C12832.h"
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

DigitalOut myled1(p13);DigitalOut myled2(p14);
DigitalOut myled3(p15);DigitalOut myled4(p16);
DigitalOut myled5(p17);DigitalOut myled6(p18);
DigitalOut myled7(p19);DigitalOut myled8(p20);

DigitalIn toggle1(p21);DigitalIn toggle2(p22);
DigitalIn toggle3(p23);DigitalIn toggle4(p24);
DigitalIn toggle5(p25);DigitalIn toggle6(p26);
DigitalIn toggle7(p27);DigitalIn toggle8(p28);

int main(){
    while(1){
        if(toggle1==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 1");
            myled1 = 1;
            wait_ms(500);
            myled1 = 0;
            printf("Switch1! is: %d\n", toggle1.read());
        }
        if(toggle2==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 2");
            myled2 = 1;
            wait_ms(500);
            myled2 = 0;
            printf("Switch2! is: %d\n", toggle2.read());}
        if(toggle3==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 3");
            myled3 = 1;
            wait_ms(500);
            myled3 = 0;
            printf("Switch3! is: %d\n", toggle3.read());}
        if(toggle4==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 4");
            myled4 = 1;
            wait_ms(500);
            myled4 = 0;
            printf("Switch4! is: %d\n", toggle4.read());}
        if(toggle1==5){
            lcd.locate(0,3);
            lcd.printf("Sensor 5");
            myled5 = 1;
            wait_ms(500);
            myled5 = 0;
            printf("Switch5! is: %d\n", toggle5.read());
        }
        if(toggle6==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 6");
            myled6 = 1;
            wait_ms(500);
            myled6 = 0;
            printf("Switch6! is: %d\n", toggle6.read());}
        if(toggle7==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 7");
            myled7 = 1;
            wait_ms(500);
            myled7 = 0;
            printf("Switch7! is: %d\n", toggle7.read());}
        if(toggle8==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 8");
            myled8 = 1;
            wait_ms(500);
            myled8 = 0;
            printf("Switch8! is: %d\n", toggle8.read());
        }
        wait(0.2);
        
    }
    
    
    
}
