#include "reg51.h"

void delay(void) {
    unsigned int i,j;

    for(i = 0 ; i < 100; i++) {
        for(j = 9 ; j < 1275; j++) {

        }
    }

    
}

void main() {
    while(1) {
        P2 = 0xFF;
        delay();

        P2 = 0x00;
        delay();
    }
}
