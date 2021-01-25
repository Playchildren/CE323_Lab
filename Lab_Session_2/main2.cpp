// print on LCD display 

#include "mbed.h"
#include "C12832.h"

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
int main(){
    lcd.printf("Hello, world!\n");
    
    }
