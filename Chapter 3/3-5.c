#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;
    int r;

    if (n < 0)
        n = -n;

    do {
        r = n % b;

        if (r < 10)
            s[i++] = r + '0';
        else
            s[i++] = r - 10 + 'a';

    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
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