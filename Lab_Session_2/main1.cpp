//  Time interrupt 

#include mbed.h
Timeout flipper;
DigitalOut led1(LED1);
DigitalOut led2(LED2);

void flip(){
    led2 = !led2;
    }

int main(){
    led2 = 1;
    flipper.attach(&flip, 2);  to call flip after 2s
    
    
while(1){
    led1 = !led1;
    wait(0.5);
    } }
