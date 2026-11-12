#include <reg51.h>

void delay(void) {
    unsigned i,j;
    for(i = 0 ; i < 100 ;i++) {
        for(j = 0 ; j < 1275; j++) {}
    }
}

//========asciii values=======
void main(void) {
    unsigned char ch;

    while (1)
    {
        for(ch = 'A'; ch <= 'Z'; ch++) {
            P2 = ch;
            delay();
        }
    }
    
}