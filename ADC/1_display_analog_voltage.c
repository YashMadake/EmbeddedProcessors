#include <p18f4550.h>
#include <delays.h>

void lcd_cmd(unsigned char cmd) {

    LATD = cmd;
    LATEbits.LATE0 = 0;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
    Delay10KTCYx(1);
    LATEbits.LATE2 = 0;
    Delay10KTCYx(1);
}
void lcd_data(unsigned char data) {

    LATD = data;
    LATEbits.LATE0 = 1;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
    Delay10KTCYx(1);
    LATEbits.LATE2 = 0;
    Delay10KTCYx(1);
}

void lcd_string(const rom char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

void lcd_num(unsigned int n) {
    lcd_data((n/1000) + '0');
    lcd_data(((n/100)%10) + '0');
    lcd_data(((n/10)%10)+ '0');
    lcd_data((n%10) + '0');
}

unsigned int adc_read() {
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO == 1);
    return ((ADRESH << 8) | ADRESL);

}

void main() 
{
    unsigned int adc_value;

    TRISA = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;

    LATD = 0x00;
    LATE = 0x00;

    ADCON1 = 0x0E;
    ADCON2 = 0xAE;
    ADCON0 = 0x01;

    // LCD initialization

    while(1) 
    {
        adc_value = adc_read();

        lcd_cmd(0x80);
        lcd_string("ADC Value:");
        lcd_cmd(0xC0);
        lcd_num(adc_value);

        Delay10KTCYx(10);
    }

}