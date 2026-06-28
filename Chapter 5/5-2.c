#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

float getfloat(float *);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int main(void) 
{

    return 0;
}

float getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch();

        if (!isdigit(next)) {
            if (next != EOF)
                ungetch(next);
            ungetch(c);
            return 0;
        }

        c = next;
    }

    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
