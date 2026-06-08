#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i, len = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++len;
    }

    if (c == '\n') {
        ++len;
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }
    if (i < lim)
        s[i] = '\0';
    else
        s[lim-1] = '\0';
    return len;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}