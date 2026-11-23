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

#include <delays.h>

void main() 
{
    ADCON1 = 0x0F;

    TRISCbits.TRISC2 = 0;   //  CCP1 output

    PR2 = 77;

    CCP1CON = 0x0C;     // PWM mode

    T2CON = 0x06;

    while(1) {

        CCPR1L = 15;
        CCP1CON = 0x2C;

        delay(200);
    }

}