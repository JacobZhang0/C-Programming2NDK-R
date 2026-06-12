#include <stdio.h>

#define MAXSTACK 1000

int stack[MAXSTACK];
int sp = 0;

void push(int c);
int pop(void);
int match(int open, int close);

int main()
{
    int c, prev = 0;
    int state = 0;
    /*
        0 = normal
        1 = string
        2 = char
        3 = block comment
        4 = line comment
    */

    while ((c = getchar()) != EOF) {

        /* LINE COMMENT */
        if (state == 4) {
            if (c == '\n')
                state = 0;
        }

        /* BLOCK COMMENT */
        else if (state == 3) {
            if (prev == '*' && c == '/')
                state = 0;
        }

        /* STRING */
        else if (state == 1) {
            if (c == '"' && prev != '\\')
                state = 0;
        }

        /* CHAR CONSTANT */
        else if (state == 2) {
            if (c == '\'' && prev != '\\')
                state = 0;
        }

        /* NORMAL CODE */
        else {
            /* detect comments */
            if (prev == '/' && c == '/')
                state = 4;
            else if (prev == '/' && c == '*')
                state = 3;

            /* detect strings / chars */
            else if (c == '"')
                state = 1;
            else if (c == '\'')
                state = 2;

            /* stack logic */
            else if (c == '(' || c == '[' || c == '{')
                push(c);

            else if (c == ')' || c == ']' || c == '}') {
                if (sp == 0) {
                    printf("Error: extra closing delimiter\n");
                    return 1;
                }

                int open = pop();

                if (!match(open, c)) {
                    printf("Error: mismatched delimiter\n");
                    return 1;
                }
            }
        }

        prev = c;
    }

    if (sp != 0)
        printf("Error: missing closing delimiter(s)\n");

    return 0;
}

void push(int c)
{
    if (sp < MAXSTACK)
        stack[sp++] = c;
}

int pop(void)
{
    if (sp > 0)
        return stack[--sp];
    return 0;
}

int match(int open, int close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

