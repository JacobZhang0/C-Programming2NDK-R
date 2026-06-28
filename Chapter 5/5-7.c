#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORAGE 1000

char *alloc(int);
char *lineptr[MAXLINES];

int readlines(char *lineptr[], char storage[], int);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int get_line(char [], int);

int main(void)
{
    return 0;
}


int readlines(char *lineptr[], char storage[], int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p;
    char *storage_end;

    p = storage;
    storage_end = storage + MAXSTORAGE;
    nlines = 0;

    while ((len = get_line(line, MAXLEN)) > 0) {

        if (nlines >= maxlines)
            return -1;

        if (p + len > storage_end)
            return -1;

        line[len - 1] = '\0';

        strcpy(p, line);

        lineptr[nlines++] = p;

        p += len;
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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