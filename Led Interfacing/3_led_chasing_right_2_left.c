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
            P2 = (0x80 >> i);
            delay();
        }
    }
}