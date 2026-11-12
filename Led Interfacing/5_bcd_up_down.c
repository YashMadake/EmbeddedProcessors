#include <reg51.h>

void delay(void) {
    unsigned i,j;
    for(i = 0 ; i < 100 ;i++) {
        for(j = 0 ; j < 1275; j++) {}
    }
}


void main(void) {
    unsigned char tens, units;

    while(1) {
        // UP counting
        for(tens = 0; tens <= 9 ; tens++) {
            for(units = 0; units <= 9 ; units++) {
                P2 = (tens << 4) | units;
                delay();
            }
        }

        // DOWN counting
        for(tens = 9 ; ; tens--) {
            for(units = 9 ;; units--){
                P2 = (tens << 4) | units;
                delay();

                if(units == 0) break;
            }
            if(tens == 0){
                break;
            }
        }
    }
}