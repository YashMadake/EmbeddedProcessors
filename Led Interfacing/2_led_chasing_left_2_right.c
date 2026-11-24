#include <reg51.h>

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}

void main(void)
{
    unsigned char i;

    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            P2 = (1 << i);
            delay();
        }
    }
}
/*
Msb shift from left to right lsb
00000001
00000010
00000100
00001000
00010000
00100000
01000000
10000000
*/
