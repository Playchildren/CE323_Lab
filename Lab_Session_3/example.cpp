// blink led then read and feedback the state on the print 

#include "mbed.h"

DigitalOut led(p5);

int main() {
    while (1) {
        led = !led;
        printf("Blink! LED is now %d\n", led.read());

        wait_ms(500);
    }
}

