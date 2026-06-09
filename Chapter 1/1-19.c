#include <stdio.h>

#define MAXLENGTH 1000

int get_line(char line[], int max);
void reverse(char line[], char reversed[]);

int main()
{
    int len;
    char stored[MAXLENGTH];
    char reversed[MAXLENGTH];
    while ((len = get_line(stored, MAXLENGTH)) > 0) { 
        reverse(stored, reversed);
        printf("%s", reversed);
    }
    return 0;
}

int get_line(char line[], int max) 
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < max - 1)
            line[i] = c;
    }

    if (c == '\n') {
        if (i < max - 1)
            line[i] = c;
        ++i;
    }
    if (i < max)
        line[i] = '\0';
    else
        line[max-1] = '\0';
    return i;
}

void reverse(char line[], char reversed[])
{
    int i, j;
    for (i = 0; line[i] != '\0'; ++i)
        ;
    if (i > 0 && line[i - 1] == '\n')
        --i;
    for (j = 0; i > 0; j++) {
        reversed[j] = line[i - 1];
        --i;
    }

    reversed[j] = '\0';
    
}