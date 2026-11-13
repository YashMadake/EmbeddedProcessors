#include <p18f4550.h>

#include <delays.h>


void main() {
    ADCON1 = 0x0F;

    TRISB = 0xFF; // Portb input
    TRISD = 0x00; // PortD output
    TRISC = 0x00; // PORTC output

    LATD = 0x00;
    LATC = 0x00;

    while (1)
    {
        /* Switch 0 : Relay and buzzer on */
        if(PORTBbits.RB0 == 0) {
            LATCbits.LATC0 = 1;
            LATCbits.LATC1 = 1;
            LATD = 0x00;
        }

               // Switch 1: Relay and Buzzer OFF, Flash LEDs
        else if(PORTBbits.RB1 == 0) {
            LATCbits.LATC0 = 0;
            LATCbits.LATC1 = 0;

            LATD = 0xFF;
            Delay10KTCYx(100);

            LATD = 0x00;
            Delay10KTCYx(100);
        }
    }
    
}
