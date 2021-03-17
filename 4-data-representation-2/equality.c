#include <stdio.h>

int main(void)
{
    float a = 1.0f;
    float b = a / 3.0f - 1.0f;
    float c = (b + 1.0f) * 3.0f;

    printf("%f %f\n", a, c);

    if (a == c)
        printf("Equal\n");
    else
        printf("Not Equal\n");

    printf("%.10f %.10f\n", a, c);

    return 0;
}
