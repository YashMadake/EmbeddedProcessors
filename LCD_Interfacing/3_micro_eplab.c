#include <p18f4550.h>

#include <delays.h>

void lcd_cmd(unsigned char cmd) {

    LATD = cmd;

    LATEbits.LATE0 = 0;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
    DelayKTCYx(1);
    LATEbits.LATE2 = 0;

    DelayKTCYx(1);
}
void lcd_cmd(unsigned char data) {

    LATD = data;

    LATEbits.LATE0 = 1;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
    DelayKTCYx(1);
    LATEbits.LATE2 = 0;

    DelayKTCYx(1);
}

void lcd_string(const rom char * str) {
    while(*str != '\0')
    {
        lcd_data(*str);
        str++;
    }
}


void main() {
    ADCON1 = 0x0F;

    TRISD = 0x00;
    TRISE = 0x00;

    LATD = 0x00;
    LATE = 0x00;

    Delay10KTCYx(10);

    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x06);

    // first line
    lcd_cmd(0x80);
    lcd_string("microcontroller");
    // 2nd line
    lcd_cmd(0xC0);
    lcd_string("Embedded Lab");

    while(1);
}