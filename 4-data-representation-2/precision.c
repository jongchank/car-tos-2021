#include <stdio.h>

int main(void)
{
    float sum = 0.0f;

    for (int i = 0; i < 1000; i++) {
        sum += 0.001f;
    }
    printf("%f\n", sum);

    return 0;
}
