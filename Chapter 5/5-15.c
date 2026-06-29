#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);
int get_line(char *s, int lim);
char *alloc(int n);
void swap(void *v[], int i, int j);
int numcmp(const char *s1, const char *s2);
void q_sort(void *v[], int left, int right, int (*comp)(const char *, const char *));

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    while (--argc > 0) {
        argv++;

        if (strcmp(*argv, "-n") == 0)
            numeric = 1;
        else if (strcmp(*argv, "-r") == 0)
            reverse = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        q_sort((void **) lineptr, 0, nlines - 1,
               numeric ? numcmp : strcmp);

        writelines(lineptr, nlines, reverse);

        return 0;
    }

    printf("input too big to sort\n");
    return 1;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;

        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }

    return nlines;
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

int get_line(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 &&
           (c = getchar()) != EOF &&
           c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return (int)(s - start);
}

char *alloc(int n)
{
    if ((size_t)(allocbuf + ALLOCSIZE - allocp) >= (size_t)n) {
        allocp += n;
        return allocp - n;
    }

    return NULL;
}

int numcmp(const char *s1, const char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void q_sort(void *v[], int left, int right, int (*comp)(const char *, const char *))
{   
    int i, last;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)((char *)v[i], (char *)v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
