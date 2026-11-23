
#include <p18f4550.h>

void timer0_isr(void);

#pragma code high_vector = 0x08
void high_vector(void)
{
    _asm
        GOTO timer0_isr
    _endasm
}
#pragma code

#pragma interrupt timer0_isr
void timer0_isr(void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        TMR0H = 0xFF;
        TMR0L = 0x9E;

        LATBbits.LATB0 = !LATBbits.LATB0;

        INTCONbits.TMR0IF = 0;
    }
}

void main()
{
    ADCON1 = 0x0F;

    TRISBbits.TRISB0 = 0;
    LATBbits.LATB0 = 0;

    // Timer0 configuration
    T0CON = 0x87;

    // Load Timer0
    TMR0H = 0xFF;
    TMR0L = 0x9E;

    // Enable Timer0 interrupt
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;

    while(1);
}

/*
4. Working of Timer0
1. Timer0 is a 16-bit timer configured using T0CON.
2. Internal instruction clock (Fosc/4) is selected.
3. Prescaler of 1:256 is selected.
4. Timer0 starts counting from the preload value.
5. When Timer0 overflows, TMR0IF flag becomes 1.
6. Timer0 interrupt is generated.
7. ISR executes and reloads Timer0.
8. RB0 output is toggled.
9. This process repeats continuously to generate a 100 Hz square wave.
5. T0CON Register
T0CON = 0x87
T0CON: 10000111

Bit	Name	Function
7	TMR0ON	Timer0 ON/OFF
6	T08BIT	8-bit / 16-bit mode
5	T0CS	Clock source selection
4	T0SE	Clock edge selection
3	PSA	Prescaler assignment
2-0	T0PS	Prescaler selection

Configuration:
- Timer0 ON.
- 16-bit mode.
- Internal clock.
- Prescaler enabled.
- Prescaler 1:256.*/