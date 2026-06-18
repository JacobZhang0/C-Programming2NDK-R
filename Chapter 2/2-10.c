#include <stdio.h>

int lower(int c);

int main(void)
{
    int param = lower(65);
    printf("%d", param);
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}