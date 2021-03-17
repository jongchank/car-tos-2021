#include <stdio.h>

int main(void)
{
    unsigned char uc = 255;
    uc++;
    printf("255 + 1 = %u\n", uc);

    uc = 0;
    uc--;
    printf("0 - 1 = %u\n", uc);

    char sc = 127;
    sc++;
    printf("127 + 1 = %d\n", sc);

    sc = -128;
    sc--;
    printf("-128 - 1 = %d\n", sc);

    return 0;
}
