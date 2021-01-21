// Use different frequency to blink different lights at the same time.

#include "mbed.h"
DigitalOut myled1(p5);
DigitalOut myled2(p6);
DigitalOut myled3(p7);
DigitalOut myled4(p8);
int i=0;

int main(){
    while(1){
        
        myled1 = 0;
        myled2 = 0;
        myled3 = 0;
        myled4 = 0;
        if (i % 20 == 0){
            myled1 = !myled1;
            myled2 = !myled2;
            myled3 = !myled3;
            myled4 = !myled4;
        }
        else if (i % 10 == 0){
            myled1 = !myled1;
            myled2 = !myled2;
            myled3 = !myled3;
        }
        else if (i % 5 == 0){
            myled2 = !myled2;
        }
        else if (i % 2 == 0){
            myled1 = !myled1;
        }

        wait_ms(100);
        i = i + 1;

    }  
}
