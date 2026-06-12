#include <stdio.h>


int main()
{
    int c;
    int state = 0;

    while ((c = getchar()) != EOF) {

        if (state == 0) {
            if (c == '/')
                state = 1;
            else
                putchar(c);
        }

        else if (state == 1) {
            if (c == '*')
                state = 2;
            else {
                putchar('/');
                putchar(c);
                state = 0;
            }
        }

        else if (state == 2) {
            if (c == '*')
                state = 3;
        }

        else if (state == 3) {
            if (c == '/')
                state = 0;
            else if (c != '*')
                state = 2;
        }
    }

    if (state == 1)
        putchar('/');

    return 0;
}