#include <stdio.h>

int main() 
{
    int c = getchar() != EOF;
    printf("%d", c);
    // 0 if ctr-d; 1 for others
}