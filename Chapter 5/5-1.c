#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getint(int *);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int main(void) 
{

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next = getch();

        if (!isdigit(next)) {
            if (next != EOF) {
                ungetch(next);
            }
            ungetch(c);
            return 0;
        }
        c = next;
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
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
