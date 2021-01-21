// Use different frequence to blink same LED

#include "mbed.h"
DigitalOut myled(p5);

int main(){
    while(1){
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);   
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
        myled = 1;
        wait(2);
        myled = 0;
        wait(2);
    }  
}
