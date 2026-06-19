#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i = 0;
    int sign = n;

    if (n < 0)
        n = -n;

    do {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);

    
    int len = strlen(s);

    while (len < w) {
        for (int j = len; j >= 0; j--)
            s[j + 1] = s[j];
        s[0] = ' ';
        len++;
    }
}

void reverse(char s[])
{
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}