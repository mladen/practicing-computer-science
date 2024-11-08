#include <stdio.h>

int main()
{
    unsigned char bytes[10] = {};

    bytes[0] = 0b01001000; // Byte 0
    bytes[1] = 72;         // Byte 1

    for (int i = 0; i < 10; i++)
    {
        printf("[%2u] %3u", i, bytes[i]);

        printf("\n");
    }

    return 0;
}
