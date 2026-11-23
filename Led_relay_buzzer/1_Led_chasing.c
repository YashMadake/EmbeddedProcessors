#include <p18f4550.h>

#define SW0 PORTCbits.RC0
#define SW1 PORTCbits.RC1

void msdelay(void)
{
    unsigned int i, j;

    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}

void init(void)
{
    ADCON1 = 0x0F;

    // Switches as input
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;

    // LEDs as output
    TRISD = 0x00;

    // Initialize LEDs OFF
    LATD = 0x00;
}

void main(void)
{
    unsigned char i;

    init();

    while(1)
    {
        // Switch 0: RD0 to RD7
        if(SW0 == 0)
        {
            for(i = 0; i < 8; i++)
            {
                LATD = (1 << i);
                msdelay();
            }
        }

        // Switch 1: RD7 to RD0
        else if(SW1 == 0)
        {
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