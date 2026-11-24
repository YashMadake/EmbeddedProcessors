/*
1. Problem Statement
Write an embedded C program to control the speed of a DC motor using CCP PWM.
- PWM frequency = 4 KHz
- Duty cycle = 20% and 40%
- Show detailed calculation of PR2.
Controller: PIC18F4550
Crystal frequency: 20 MHz
2. Pin Connections
Component	PIC18F4550
CCP1 PWM Output	RC2
Motor driver input	RC2
Motor supply	External supply
Common ground	PIC GND and driver GND

Use a motor driver such as an H-bridge or suitable transistor driver. Do not connect the motor directly to RC2.

*/

#include <p18f4550.h>

void myMsDelay(unsigned int time)
{
    unsigned int i, j;

    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 665; j++)
        {
        }
    }
}

void main(void)
{
    // Configure analog pins as digital
    ADCON1 = 0x0F;

    // CCP1 output
    TRISCbits.TRISC2 = 0;

    // Configure PWM period
    PR2 = 0xBB;

    // Select PWM mode
    CCP1CON = 0x0C;

    // Start Timer2, prescaler 1:16
    T2CON = 0x07;

    while(1)
    {
        // 20% Duty Cycle
        CCPR1L = 15;
        CCP1CONbits.DC1B1 = 1;
        CCP1CONbits.DC1B0 = 0;

        myMsDelay(3000);

        // 40% Duty Cycle
        CCPR1L = 31;
        CCP1CONbits.DC1B1 = 0;
        CCP1CONbits.DC1B0 = 1;

        myMsDelay(3000);

        // 50% Duty Cycle
        CCPR1L = 39;
        CCP1CONbits.DC1B1 = 0;
        CCP1CONbits.DC1B0 = 0;

        myMsDelay(3000);

        // 60% Duty Cycle
        CCPR1L = 46;
        CCP1CONbits.DC1B1 = 1;
        CCP1CONbits.DC1B0 = 1;

        myMsDelay(3000);

        // 80% Duty Cycle
        CCPR1L = 62;
        CCP1CONbits.DC1B1 = 1;
        CCP1CONbits.DC1B0 = 0;

        myMsDelay(3000);
    }
}
