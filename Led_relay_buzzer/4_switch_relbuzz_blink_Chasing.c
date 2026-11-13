/* Write an embedded C program for interfacing button, LED, relay & buzzer as
follows
a) When Switch 0 is pressed relay and buzzer is turned ON and LED’s start
blinking.
b) When Switch 1 is pressed relay and buzzer is turned OFF and LED start chasing
from left to right in a group o
 */
#include <p18f4550.h>
#include <delays.h>

void main()
{
    unsigned char i;

    ADCON1 = 0x0F;

    TRISB = 0xFF;
    TRISD = 0x00;
    TRISC = 0x00;

    LATD = 0x00;
    LATC = 0x00;

    while(1)
    {
        // Switch 0: Relay and Buzzer ON
        // All LEDs blinking

        if(PORTBbits.RB0 == 0)
        {
            LATCbits.LATC0 = 1;
            LATCbits.LATC1 = 1;

            LATD = 0xFF;
            Delay10KTCYx(100);

            LATD = 0x00;
            Delay10KTCYx(100);
        }

        // Switch 1: Relay and Buzzer OFF
        // LEDs chasing in group of two

        else if(PORTBbits.RB1 == 0)
        {
            LATCbits.LATC0 = 0;
            LATCbits.LATC1 = 0;

            for(i = 0; i < 4; i++)
            {
                LATD = (0x03 << (i * 2));
                Delay10KTCYx(100);
            }
        }

        else
        {
            LATD = 0x00;
        }
    }
}
