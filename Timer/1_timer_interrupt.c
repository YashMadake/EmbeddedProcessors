#include <p18f4550.h>
#include "vector_relocate.h"

void timer_isr(void);

void main(void)
{
    ADCON1 = 0x0F;

    // Configure RB0 as output
    TRISBbits.TRISB0 = 0;
    LATBbits.LATB0 = 0;

    // Configure Timer0
    T0CON = 0x03;       // 16-bit, internal clock, prescaler 1:16

    // Load Timer0 preload value
    TMR0H = 0x6D;
    TMR0L = 0x84;

    // Enable Timer0 interrupt
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;

    // Start Timer0
    T0CONbits.TMR0ON = 1;

    while(1);
}

// Reset interrupt vector
extern void _startup(void);

#pragma code RESET_INTERRUPT_VECTOR = 0x1000
void _reset(void)
{
    _asm
        goto _startup
    _endasm
}

#pragma code

// High priority interrupt vector
#pragma code HIGH_INTERRUPT_VECTOR = 0x1008
void high_ISR(void)
{
    _asm
        goto timer_isr
    _endasm
}

#pragma code

// Timer0 interrupt service routine
#pragma interrupt timer_isr
void timer_isr(void)
{
    // Reload Timer0
    TMR0H = 0x6D;
    TMR0L = 0x84;

    // Toggle LED
    LATBbits.LATB0 = ~LATBbits.LATB0;

    // Clear Timer0 interrupt flag
    INTCONbits.TMR0IF = 0;
}