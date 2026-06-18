#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
    unsigned output = setbits(20, 20, 4, 2321);
    printf("%d", output);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    unsigned mask = ~(0u << n);

    x &= ~(mask << (p + 1 - n));
    x |= (y & mask) << (p + 1 - n);

    return x;
}