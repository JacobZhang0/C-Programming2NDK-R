#include <stdio.h>


unsigned rightrot(unsigned x, int n);

int main(void)
{
    int param = rightrot(10, 4);
    printf("%d", param);
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    if (n == 0)
        return x;

    int bits = 32;
    n %= bits;

    return (x >> n) | (x << (bits - n));
}