/*Write an embedded C program for interfacing button, LED, relay & buzzer as follows:

a) When Switch 0 is pressed, relay and buzzer are turned ON and LEDs start chasing from left to right.

b) When Switch 1 is pressed, relay and buzzer are turned OFF and LEDs start chasing from right to left.
*/

#include <p18f4550.h>

#include <delays.h>


void main( ) {
    unsigned char i;

    ADCON1 = 0x0F;

    TRISB = 0xFF;   // PORTD input
    TRISD = 0x00;   // PORTD output
    TRISC = 0x00;   // PORTD output

    LATD = 0x00;
    LATC = 0x00;

    while(1) {

        // Switch 0: Relay, Buzzer ON
        // LED chasing Left to Right
        if(PORTBbits.RB0 == 0) {
            LATCbits.LATC0 = 1;
            LATCbits.LATC1 = 1;

            for(i = 0 ; i < 8 ; i++) {
                LATD = (0x01 << i);
                Delay10KTCYx(100);
            }
        }
         // Switch 1: Relay, Buzzer OFF
        // LED chasing Right to Left

        else if(PORTBbits.RB1 == 0) {
            LATCbits.LATC0 = 0;
            LATCbits.LATC1 = 0;
            
            for(i = 0 ; i < 8 ; i++) {
                LATD = (0x80 >> i);
                Delay10KTCYx(100);
            }
        }
        else {
            LATD = 0x00;
        }
    }
}