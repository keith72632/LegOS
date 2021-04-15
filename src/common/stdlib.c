#include <stdint.h>

void bzero(void *dest, int bytes)
{
    char *d = dest;
    while(bytes--)
    {
        *d++ = 0;
    }
}

void memcpy(void *dest, void *src, int bytes)
{
    char *d = dest, *s = src;
    while(bytes--)
    {
        *d++ = *s++;
    }
}

