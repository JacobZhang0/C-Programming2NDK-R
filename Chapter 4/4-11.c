#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define NAME 'n'
#define VARIABLE 'v'

int sp = 0;
double val[MAXVAL];

double vars[26];
double last = 0.0;

char line[MAXOP];
int li = 0;

int getop(char []);
void push(double);
double pop(void);
int getLine(char [], int);

/* reverse polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    int var = -1;

    while (getLine(line, MAXOP) > 0) {
        li = 0;

        while ((type = getop(s)) != '\n') {
            switch (type) {

            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;

            case '?':
                if (sp > 0)
                    printf("Top: %.8g\n", val[sp - 1]);
                else
                    printf("error: stack empty\n");
                break;

            case 'd':
                if (sp > 0)
                    push(val[sp - 1]);
                else
                    printf("error: stack empty\n");
                break;

            case 's':
                if (sp >= 2) {
                    double temp = val[sp - 1];
                    val[sp - 1] = val[sp - 2];
                    val[sp - 2] = temp;
                } else
                    printf("error: not enough elements\n");
                break;

            case 'c':
                sp = 0;
                break;

            case NAME:
                if (s[0] == 's' && s[1] == 'i' && s[2] == 'n' && s[3] == '\0')
                    push(sin(pop()));

                else if (s[0] == 'e' && s[1] == 'x' && s[2] == 'p' && s[3] == '\0')
                    push(exp(pop()));

                else if (s[0] == 'p' && s[1] == 'o' && s[2] == 'w' && s[3] == '\0') {
                    op2 = pop();
                    push(pow(pop(), op2));
                }
                else
                    printf("error: unknown function %s\n", s);
                break;

            case VARIABLE:
                var = s[0] - 'A';
                push(vars[var]);
                break;

            case '=':
                if (var >= 0)
                    vars[var] = val[sp - 1];
                else
                    printf("error: no variable name\n");
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }

        /* end of line */
        if (sp > 0) {
            last = pop();
            printf("\t%.8g\n", last);
        }
    }

    return 0;
}

int getop(char s[])
{
    static int buf = EOF;  
    int i = 0, c;

    if (buf != EOF) {
        c = buf;
        buf = EOF;
    } else {
        c = getchar();
    }

    while (c == ' ' || c == '\t')
        c = getchar();

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[i++] = c = getchar()))
            ;

    if (c == '.')
        while (isdigit(s[i++] = c = getchar()))
            ;

    s[i - 1] = '\0';

    if (c != EOF)
        buf = c;      

    return NUMBER;
}

/* push */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

/* pop */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getline */
int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 &&
                (c = getchar()) != EOF &&
                c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}