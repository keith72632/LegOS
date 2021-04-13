#include "../../includes/kernel/uart.h"

void putc(char character)
{
    uart_putc(character);
}

void puts(char *str)
{
    uint32_t i = 0;
    while(str[i] != '\0')
    {
        putc(str[i]);
        i++;
    }
}

unsigned char getc()
{
    uart_getc();
}

