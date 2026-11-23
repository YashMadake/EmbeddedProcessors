#include <reg51.h>

void delay(void)
{
    unsigned int i, j;

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 1275; j++)
        {
        }
    }
}

void main(void)
{
    unsigned int i;
    unsigned char bcd;

    while (1)
    {
        // UP counting
        for (i = 0; i <= 99; i++)
        {
            bcd = ((i / 10) << 4) | (i % 10);

            P2 = bcd;
            delay();
        }

        // DOWN counting
        for (i = 99; i > 0; i--)
        {
            bcd = ((i / 10) << 4) | (i % 10);

            P2 = bcd;
            delay();
        }

        P2 = 0x00;
        delay();
    }
}