#include <reg51.h>

void delay(void) {
    unsigned i,j;
    for(i = 0 ; i < 8 ;i++) {
        for(j = 0 ; j < 1275; j++) {}
    }
}

// ======= Hex counter up/down========
void main(void) {
    unsigned int i;

    while(1) {
        
        for(i = 0 ; i <= 255 ; i++) {
            P2 = (unsigned char) i;
            delay();
        }
        for(i = 255 ; i >= 0 ; i--) {
            P2 = (unsigned char) i;
            delay();
        }


    }
}