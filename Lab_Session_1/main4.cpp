// Use different frequency to blink different lights one by one

#include "mbed.h"
DigitalOut myled1(p5);
DigitalOut myled2(p6);
DigitalOut myled3(p7);
DigitalOut myled4(p8);
int i;
int main(){
    while(1){
        for(i=0;i<10;i++){
            myled1 = 1;
            wait(0.2);
            myled1 = 0;
            wait(0.2);  
            printf("This is Red,as 0.2s\n");
            }
        for(i=0;i<10;i++){
            myled2 = 1;
            wait(0.5);
            myled2 = 0;
            wait(0.5);  
            printf("This is Blue,as 0.5s\n");
            }
            
        for(i=0;i<10;i++){
            myled3 = 1;
            wait(1);
            myled3 = 0;
            wait(1);  
            printf("This is Yellow,as 1.0s\n");
            }
            
        for(i=0;i<10;i++){
            myled4 = 1;
            wait(2);
            myled4 = 0;
            wait(2);  
            printf("This is White,as 2.0s\n");
            }    
    }  
}
