// Blink a LED 

#include "mbed.h"
DigitalOut myled(p5);

int main(){
    while(1){
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);   
    }  
}
