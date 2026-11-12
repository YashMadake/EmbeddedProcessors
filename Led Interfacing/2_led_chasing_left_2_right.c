#include <reg51.h>

void delay(void) {
    unsigned i, j;

    for(i = 0 ; i < 100; i++) {
        for(j = 0 ; j < 1275; j++) {

        }
    }
}

void main(void) {
    unsigned char pattern;
    unsigned char i;
    while(1) {
        pattern = 0x01;
        for(i = 0 ; i < 8 ;i++) {
            P2 = pattern;
            delay();

            pattern = pattern << 1;
        }
    }
}