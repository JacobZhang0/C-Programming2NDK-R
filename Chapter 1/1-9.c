#include <stdio.h>

int main() 
{
    int c;
    int pchar = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pchar == 1) {
                ;
            }
            if (pchar == 0) {
                putchar(c);
                ++pchar;
            }
        }
        if (c != ' ') {
            pchar = 0;
            putchar(c);
        }

    }
}