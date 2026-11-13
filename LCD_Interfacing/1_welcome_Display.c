
#include <p18f4550.h>
#include <delays.h>

void lcd_cmd(unsigned char cmd)
{
    LATD = cmd;

    LATEbits.LATE0 = 0;  // RS = 0
    LATEbits.LATE1 = 0;  // RW = 0
    LATEbits.LATE2 = 1;  // E = 1

    Delay10KTCYx(1);

    LATEbits.LATE2 = 0;

    Delay10KTCYx(1);
}

void lcd_data(unsigned char data)
{
    LATD = data;

    LATEbits.LATE0 = 1;  // RS = 1
    LATEbits.LATE1 = 0;  // RW = 0
    LATEbits.LATE2 = 1;  // E = 1

    Delay10KTCYx(1);

    LATEbits.LATE2 = 0;

    Delay10KTCYx(1);
}

void lcd_string(const rom char *str)
{
    while(*str != '\0')
    {
        lcd_data(*str);
        str++;
    }
}

void main()
{
    ADCON1 = 0x0F;

    TRISD = 0x00;
    TRISE = 0x00;

    LATD = 0x00;
    LATE = 0x00;

    Delay10KTCYx(10);

    // LCD Initialization
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x06);

    // First Line
    lcd_cmd(0x80);
    lcd_string("Welcome");

    // Second Line
    lcd_cmd(0xC0);
    lcd_string("To Embedded Lab");

    while(1);
}
