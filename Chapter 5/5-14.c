#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN   1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);

int get_line(char *, int);
char *alloc(int);

int main(int argc, char *argv[])
{
    int nlines;
    int reverse = 0;

    if (argc > 1 && strcmp(argv[1], "-r") == 0)
        reverse = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines, reverse);
        return 0;
    }

    printf("input too big to sort\n");
    return 1;
}

void writelines(char *lineptr[], int nlines, int reverse)
{
    if (!reverse)
        while (nlines-- > 0)
            printf("%s\n", *lineptr++);
    else
        while (nlines-- > 0)
            printf("%s\n", lineptr[nlines]);
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int get_line(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - start;
}

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else
        return NULL;
}