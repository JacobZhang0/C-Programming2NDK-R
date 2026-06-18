#include <stdio.h>
#include <string.h>

int main(void)
{
    int lim = 1000, c;
    int i = 0;
    char s[lim];
    while (i < lim - 1) {
        c = getchar();

        if (c == EOF) 
            break;

        if (c == '\n')
            break;

        s[i] = c;
        ++i;
        

    }
}