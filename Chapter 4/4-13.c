#include <stdio.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void) 
{
    char s[100];

    itoa(0, s);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[])
{
    static int i = 0;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s);

    s[i++] = (n % 10) + '0';
    s[i] = '\0';
}

void reverse(char s[])
{
    static int i = 0, j = 0, init = 1;
    char temp;

    if (init) {
        i = 0;
        j = 0;

        while (s[j] != '\0')
            j++;

        j--;
        init = 0;
    }

    if (i >= j) {
        init = 1; 
        i = j = 0;
        return;
    }

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    i++;
    j--;

    reverse(s);
}