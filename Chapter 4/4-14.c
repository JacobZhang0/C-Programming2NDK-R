#include <stdio.h>

#define swap(t,x,y) {t temp = x; x = y; y = temp;}

int main(void) 
{
    int a = 4; // you need vars
    int b = 2; // you need vars
    swap(int, a, b);
    return 0;
}