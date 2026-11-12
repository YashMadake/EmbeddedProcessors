#include <reg51.h>

void delay(void) {
    unsigned i,j;
    for(i = 0 ; i < 100 ;i++) {
        for(j = 0 ; j < 1275; j++) {}
    }
}


void main(void) {
    while(1) {
        P2 = 0xAA;
        delay();

        P2 = 0x55;
        delay();
    }
}