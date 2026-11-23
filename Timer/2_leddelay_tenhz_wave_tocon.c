
#include <p18f4550.h>

void main()
{
    unsigned char count = 0;

    ADCON1 = 0x0F;

    TRISBbits.TRISB0 = 0;
    TRISD = 0x00;

    LATBbits.LATB0 = 0;
    LATD = 0x00;

    // Timer0 configuration
    T0CON = 0x87;

    while(1)
    {
        // Load Timer0
        TMR0H = 0xFC;
        TMR0L = 0x2F;

        INTCONbits.TMR0IF = 0;

        // Wait for Timer0 overflow
        while(INTCONbits.TMR0IF == 0);

        // Generate 10Hz square wave
        LATBbits.LATB0 = !LATBbits.LATB0;

        count++;

        // LED toggle after 100ms
        if(count == 2)
        {
            LATD = ~LATD;
            count = 0;
        }
    }
}
/*
4. T0CON Register
T0CON = 0x87
8-bit T0CON register



Binary: 10000111

Bit	Name	Function
7	TMR0ON	Timer0 ON/OFF
6	T08BIT	8-bit/16-bit mode
5	T0CS	Clock source
4	T0SE	Clock edge
3	PSA	Prescaler assignment
2-0	T0PS	Prescaler selection

Configuration:
- Timer0 ON.
- 16-bit mode.
- Internal clock.
- Prescaler enabled.
- Prescaler 1:256.
5. Expected Output
RB0: 10 Hz square wave

PORTD LEDs

Toggle after every two Timer0 overflows, approximately 100 ms.

Important: The calculation assumes Timer0 starts counting immediately after preload. Actual polling and software overhead add a small timing error. For accurate hardware timing, account for reload latency.*/