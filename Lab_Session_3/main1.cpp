// use switch to control the blink of led
// when switch on, led on, switch off, led off

#include "mbed.h"
#include "C12832.h"
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
DigitalOut myled1(p13);
DigitalIn toggle1(p21);

int main(){
    while(1){
        if(toggle1==1){
            lcd.locate(0,3);
            lcd.printf("Sensor 1");
            myled1 = 1;
            wait_ms(500);
            myled1 = 0;
            
            
        }
        wait(0.2);
        printf("Switch! is: %d\n", toggle1.read());
        wait(0.2);
        
    }
    
    
    
}
