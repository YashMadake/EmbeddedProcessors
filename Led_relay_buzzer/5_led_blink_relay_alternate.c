#include <p18f4550.h>
#include "vector_relocate.h"

#define SW0 PORTBbits.RB0
#define SW1 PORTBbits.RB1

#define RELAY LATCbits.LATC2
#define BUZZER LATCbits.LATC3

void msdelay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}

void init(void)
{
    // Configure analog pins as digital
    ADCON1 = 0x0F;

    // Enable PORTB pull-ups
    INTCON2bits.RBPU = 0;

    // Switches as input
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;

    // Relay and buzzer as output
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC3 = 0;

    // LEDs as output
    TRISD = 0x00;

    // Initialize outputs OFF
    LATD = 0x00;
    RELAY = 0;
    BUZZER = 0;
}

void main(void)
{
    unsigned char i;

    init();

    while(1)
    {
        // Switch 0: Relay ON, buzzer ON
        // LEDs blink alternatively
        if(SW0 == 0)
        {
            RELAY = 1;
            BUZZER = 1;

            // Even LEDs ON: RD0, RD2, RD4, RD6
            LATD = 0x55;
            msdelay();

            // Odd LEDs ON: RD1, RD3, RD5, RD7
            LATD = 0xAA;
            msdelay();
        }

        // Switch 1: Relay OFF, buzzer OFF
        // LEDs chase in groups of four
        else if(SW1 == 0)
        {
            RELAY = 0;
            BUZZER = 0;

            for(i = 0; i < 2; i++)
            {
                LATD = (0x0F << (4 * i));
                msdelay();
            }
        }

        else
        {
            LATD = 0x00;
        }
    }
}