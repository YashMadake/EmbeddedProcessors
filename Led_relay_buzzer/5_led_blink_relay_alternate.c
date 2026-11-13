
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
        // Alternate LED blinking

        if(PORTBbits.RB0 == 0)
        {
            LATCbits.LATC0 = 1;
            LATCbits.LATC1 = 1;

            LATD = 0x55;
            Delay10KTCYx(100);

            LATD = 0xAA;
            Delay10KTCYx(100);
        }

        // Switch 1: Relay and Buzzer OFF
        // Chasing in group of four

        else if(PORTBbits.RB1 == 0)
        {
            LATCbits.LATC0 = 0;
            LATCbits.LATC1 = 0;

            for(i = 0; i < 2; i++)
            {
                LATD = (0x0F << (i * 4));
                Delay10KTCYx(100);
            }
        }

        else
        {
            LATD = 0x00;
        }
    }
}
