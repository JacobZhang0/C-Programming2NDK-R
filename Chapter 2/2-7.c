#include <stdio.h>


unsigned invert(unsigned x, int p, int n);

int main(void)
{
    unsigned param = invert(2314, 4, 2);
    printf("%d\n", param);
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned base = ~(~0u << n);
    base <<= (p + 1 - n);

    return x ^ base;
}
