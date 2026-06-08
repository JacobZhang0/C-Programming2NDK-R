#include <stdio.h>

#define MAXLENGTH 1000

void remover(char line[]);
int get_line(char line[], int lim);

int main() 
{
    int len;
    char stored[MAXLENGTH];

    while ((len = get_line(stored, MAXLENGTH)) > 0) {
        remover(stored);

        if (stored[0] != '\0')
            printf("%s", stored);
    }
    return 0;
}

void remover(char line[])
{
    int i;
    for (i = 0; line[i] != '\0'; ++i) 
        ;
    if (i > 0 && line[i - 1] == '\n') 
        --i;

    while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t'))
        --i;

    line[i] = '\n';
    line[i + 1] = '\0';

    if (i == 0)
        line[0] = '\0';
}

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            line[i] = c;
        }
    }

    if (c == '\n') {
        if (i < lim - 1) {
            line[i] = c;
        }
        ++i;
    }
    if (i < lim)
        line[i] = '\0';
    else
        line[lim-1] = '\0';
    return i;
}