#include <stdio.h>

#define MAXLENGTH 1000
#define COLUMN 8

int get_line(char stored[]);
void fold(char stored[]);
char stored[MAXLENGTH];

int main()
{

    while (get_line(stored) > 0) {
        fold(stored);
    }
    return 0;
}

int get_line(char stored[]) 
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < MAXLENGTH - 1)
            stored[i] = c;
    }

    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            stored[i] = c;
        ++i;
    }
    if (i < MAXLENGTH)
        stored[i] = '\0';
    else
        stored[MAXLENGTH - 1] = '\0';
    return i;
}

void fold(char stored[])
{
    int i = 0;
    int start = 0;
    int lastblank;
    int len;

    while (stored[start] != '\0' && stored[start] != '\n') {

        lastblank = -1;

        for (i = start, len = 0; stored[i] != '\0' && stored[i] != '\n' && len < COLUMN; ++i, ++len) {
            if (stored[i] == ' ' || stored[i] == '\t')
                lastblank = i;
        }

        if (len < COLUMN) {
            while (start < i)
                putchar(stored[start++]);
            putchar('\n');
            break;
        }

        if (lastblank >= start) {
            while (start < lastblank)
                putchar(stored[start++]);

            putchar('\n');
            start = lastblank + 1;
        }
        else {
            while (start < i)
                putchar(stored[start++]);

            putchar('\n');
        }
    }
}