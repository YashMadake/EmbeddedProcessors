#include <p18f4550.h>
#include <delays.h>


void lcd_cmd(unsigned char cmd) {

    LATD = cmd;
    LATEbits.LATE0 = 0; //rs = 0;
    LATEbits.LATE1 = 0; // RW = 0;
    LATEbits.LATE2 = 1; // Enable = 1;

    Delay10KTCYx(1);
    LATEbits.LATE2 = 0; // enable 0
    
    Delay10KTCYx(1);

}


void lcd_data (unsigned char data) {
    LATD = data;
    LATEbits.LATE0 = 1;
    LATEbits.LATE1 = 0;
    LATEbits.LATE2 = 1;
    
    Delay10KTCYx(1);
    LATEbits.LATE2 = 0;

    Delay10KTCYx(1);
}


void main() {

    ADCON1 = 0x0F;
    TRISD = 0x00;
    TRISE = 0x00;

    LATD = 0x00;
    LATE = 0x00;

    // lcd INitialization

    
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x06);
    
    lcd_cmd(0x80);

    lcd_data('Y');
    lcd_data('A');
    lcd_data('S');
    lcd_data('H');
    lcd_data(' ');
    lcd_data('M');
    lcd_data('A');
    lcd_data('D');
    lcd_data('A');
    lcd_data('K');
    lcd_data('E');

    // Second line

    lcd_data('S');
    lcd_data('2');
    lcd_data('4');
    lcd_data('0');
    lcd_data('5');
    lcd_data('0');
    lcd_data('1');
    lcd_data('6');
    lcd_data('6');
    while(1);

}
/*


4. LCD Control Signals
Signal	Function
RS = 0	Command register selected
RS = 1	Data register selected
RW = 0	Write operation
RW = 1	Read operation
E	Enable signal, triggers LCD operation

5. Important LCD Commands
Command	Meaning
0x38	8-bit, 2-line mode
0x0C	Display ON, cursor OFF
0x01	Clear display
0x06	Auto increment cursor
0x80	First line position
0xC0	Second line position
*/
