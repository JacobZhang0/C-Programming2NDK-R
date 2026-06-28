#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>

#define MAXVAL 100


void push(double f);
double pop(void);


int sp = 0;
double val[MAXVAL];

int main(int argc, char *argv[])
{
    while (--argc > 0) {
        char *s = *++argv;


        if (s[1] == '\0') {
            switch (*s) {
                case '+':
                    push(pop() + pop());
                    continue;

                case '*':
                    push(pop() * pop());
                    continue;

                case '-': {
                    double op2 = pop();
                    push(pop() - op2);
                    continue;
                }

                case '/': {
                    double op2 = pop();
                    push(pop() / op2);
                    continue;
                }
            }
        }


        push(atof(s));
    }

    printf("%.8g\n", pop());
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("error: stack empty\n");
    return 0.0;
}