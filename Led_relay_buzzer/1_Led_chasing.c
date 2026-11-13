#include <p18f4550.h>

#include <delays.h>

void main() {
    unsigned char i;

    ADCON1 = 0x0F;
    TRISB = 0xFF;   // PORTB input
    TRISD = 0x00;

    while(1) {

        // switch 0 : left to right
        if(PORTBbits.RB0 == 0) {
            for(i= 0 ; i < 8 ; i++) {
                LATD = (0x01 << i);
                Delay10KTCYx(100);
            }
        } 

        else if (PORTBbots.RB1 == 0) {
            for(i = 0 ; i < 8 ; i++) {
                LATD = (0x08 >> i);
                Delay10KTCYx(200);
            }
        }
        else {
            LATD = 0x00;
        }
    }

}