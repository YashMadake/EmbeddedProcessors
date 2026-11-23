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

    // Enable PORTB internal pull-ups
    INTCON2bits.RBPU = 0;

    // Switches as input
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;

    // Relay and buzzer as output
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC3 = 0;

    // LEDs as output
    TRISD = 0x00;

    // Initialize outputs
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
        // Switch 0: Relay and buzzer ON
        // LEDs chase RD0 to RD7
        if(SW0 == 0)
        {
            RELAY = 1;
            BUZZER = 1;

            for(i = 0; i < 8; i++)
            {
                LATD = (1 << i);
                msdelay();
            }
        }

        // Switch 1: Relay and buzzer OFF
        // LEDs chase RD7 to RD0
        else if(SW1 == 0)
        {
            RELAY = 0;
            BUZZER = 0;

            for(i = 0; i < 8; i++)
            {
                LATD = (0x80 >> i);
                msdelay();
            }
        }

        else
        {
            LATD = 0x00;
        }
    }
}