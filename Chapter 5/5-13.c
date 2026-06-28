#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    return NULL;
}

int get_line(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main(int argc, char *argv[])
{
    int n = 10;
    char *lineptr[MAXLINES];
    char line[1000];
    int len, nlines = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        n = atoi(*argv + 1);

    if (n <= 0)
        return 0;

    while ((len = get_line(line, 1000)) > 0) {
        if (nlines < MAXLINES) {
            char *p = alloc(len + 1);
            if (p != NULL) {
                strcpy(p, line);
                lineptr[nlines++] = p;
            }
        }
    }

    int start = (nlines - n > 0) ? (nlines - n) : 0;

    for (int i = start; i < nlines; i++)
        printf("%s", lineptr[i]);

    return 0;
}
