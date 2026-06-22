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
int buf = EOF;
int buf_full = 0;
double vars[26];
double last = 0.0;

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
    int var = -1;

    
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
            last = pop();
            printf("\t%.8g\n", last);
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
    return 0;
}

int getch(void)
{
    if (buf_full) {
        buf_full = 0;
        return buf;
    }

    return getchar();
}

void ungetch(int c)
{
    if (buf_full)
        printf("ungetch: too many characters\n");
    else {
        buf = c;
        buf_full = 1;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (c == 'v')
        return 'v';

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

    if (isupper(c)) {
        s[0] = c;
        s[1] = '\0';
        return VARIABLE;
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
