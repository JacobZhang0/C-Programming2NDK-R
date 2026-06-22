#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define BUFSIZE 100
#define MAXVAL 100
#define NAME 'n'



int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
void ungetch(int);
int getch(void);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    
    while ((type = getop(s)) != EOF) {
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
            push((int) pop() % (int) op2);
            break;
        case '?':
            if (sp > 0) {
                printf("Top: %.8g\n", val[sp - 1]);
            }
            else 
                printf("error: stack empty\n");
            break;
        case 'd': 
            if (sp > 0)
                push(val[sp - 1]);
            else
                printf("error: stack empty\n");
            break;

        case 's': {
            if (sp >= 2) {
                double temp = val[sp - 1];
                val[sp - 1] = val[sp - 2];
                val[sp - 2] = temp;
            } else
                printf("error: not enough elements\n");
            break;
        }

        case 'c':
            sp = 0;
            break;
        case '\n':
                printf("\t%.8g\n", pop());
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
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (isalpha(c)) {
        i = 0;
        while (isalpha(c)) {
            s[i++] = c;
            c = getch();
        }
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return NAME;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c; 
    i = 0;

    if (c == '-') {
        int next_c = getch();
        if (!isdigit(next_c) && next_c != '.') {
            ungetch(next_c);
            return c; 
        }
        s[++i] = c = next_c;
    }

    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch()))
        ;

    if (c == '.') 
        while (isdigit(s[++i] = c = getch()))
            ;


    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
