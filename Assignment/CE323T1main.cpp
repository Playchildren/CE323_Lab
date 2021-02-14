// activate 8 different state of a program using these 8 different switches. 
// Each switch should be connected to a LED and show the activation of one sensor on the LCD.
// Control the frequency change of LED flashing through a Timeout timer.

#include "mbed.h"

 
DigitalOut 											// Initialize the LEDs port
myled1(p13),myled2(p14),myled3(p15),myled4(p16),
myled5(p17),myled6(p18),myled7(p19),myled8(p20);

DigitalIn 											// Initialize the toggles port  
toggle1(p21),toggle2(p22),toggle3(p23),toggle4(p24),
toggle5(p25),toggle6(p26),toggle7(p27),toggle8(p28);

Timeout flipper;									// Declares the timeout timer
Timeout flipper2;
Timeout flipper3;
float rate = 2;										// Default flicker frequency

void flip(){										// When flipper work, the frequency changes to 1
    rate = 1;
}
void flip2(){										// When flipper2 work, the frequency changes to 0.5
    rate = 0.5;
}
void flip3(){										// When flipper3 work, the frequency changes to 0.2
    rate = 0.2;
}

int main(){
    flipper.attach(&flip,8);						// 8 seconds later flipper is called
    flipper2.attach(&flip2,12);						// 12 seconds later flipper2 is called
    flipper3.attach(&flip3,16);						// 16 seconds later flipper3 is called
    while(1){
        if(toggle1==1){								// If Toggle1 is pressed
            myled1 = 1;								// blink the led
            wait(rate);								// wait
            myled1 = 0;								// invert the led state
            printf("Switch1! is: %d\n", toggle1.read());			
        }											// Print the current information in Terminal
        if(toggle2==1){
            myled2 = 1;
            wait(rate);
            myled2 = 0;
            printf("Switch2! is: %d\n", toggle2.read());}
        if(toggle3==1){
            myled3 = 1;
            wait(rate);
            myled3 = 0;
            printf("Switch3! is: %d\n", toggle3.read());}
        if(toggle4==1){
            myled4 = 1;
            wait(rate);
            myled4 = 0;
            printf("Switch4! is: %d\n", toggle4.read());}
        if(toggle5==1){
            myled5 = 1;
            wait(rate);
            myled5 = 0;
            printf("Switch5! is: %d\n", toggle5.read());
        }
        if(toggle6==1){
            myled6 = 1;
            wait(rate);
            myled6 = 0;
            printf("Switch6! is: %d\n", toggle6.read());}
        if(toggle7==1){
            myled7 = 1;
            wait(rate);
            myled7 = 0;
            printf("Switch7! is: %d\n", toggle7.read());}
        if(toggle8==1){
            myled8 = 1;
            wait(rate);
            myled8 = 0;
            printf("Switch8! is: %d\n", toggle8.read());
        }
        wait(rate); 
    }
}
