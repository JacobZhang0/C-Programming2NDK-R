#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

void detab(char in[], char out[], int m, int n);
void entab(char in[], char out[], int m, int n);
int get_line(char stored[]);

int next_tab(int column, int m, int n);

int main(int argc, char *argv[])
{
    char stored[MAXLENGTH];
    char output[MAXLENGTH];

    int m = 0, n = 8; 

    int c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        c = (*argv)[1];

        if (c == 'm')
            m = atoi(*argv + 2); 
        else if (c == '+')
            n = atoi(*argv + 1);   
        else if (c == 'e') {
            while (get_line(stored) > 0) {
                entab(stored, output, m, n);
                printf("%s", output);
            }
        }
        else if (c == 'd') {
            while (get_line(stored) > 0) {
                detab(stored, output, m, n);
                printf("%s", output);
            }
        }
        else {
            printf("Illegal option\n");
            return -1;
        }
    }

    return 0;
}

int next_tab(int column, int m, int n)
{
    if (column < m)
        return m;

    return m + ((column - m) / n + 1) * n;
}

void detab(char in[], char out[], int m, int n)
{
    int i, k = 0;
    int column = 0;

    for (i = 0; in[i] != '\0'; ++i) {
        if (in[i] == '\n') {
            out[k++] = '\n';
            column = 0;
        }
        else if (in[i] == '\t') {
            int next = next_tab(column, m, n);

            while (column < next) {
                out[k++] = ' ';
                ++column;
            }
        }
        else {
            out[k++] = in[i];
            ++column;
        }
    }

    out[k] = '\0';
}


void entab(char in[], char out[], int m, int n)
{
    int i, k = 0;
    int column = 0;
    int space_count = 0;

    for (i = 0; in[i] != '\0'; ++i) {
        if (in[i] == ' ') {
            space_count++;
            column++;

            if (column == next_tab(column, m, n)) {
                out[k++] = '\t';
                space_count = 0;
            }
        }
        else {
            while (space_count-- > 0)
                out[k++] = ' ';

            space_count = 0;

            out[k++] = in[i];

            if (in[i] == '\n')
                column = 0;
            else
                column++;
        }
    }

    out[k] = '\0';
}

int get_line(char stored[])
{
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < MAXLENGTH - 1)
            stored[i] = c;

    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            stored[i] = c;
        ++i;
    }

    stored[i < MAXLENGTH ? i : MAXLENGTH - 1] = '\0';
    return i;
}