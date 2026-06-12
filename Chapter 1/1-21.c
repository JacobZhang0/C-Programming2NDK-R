#include <stdio.h>

#define MAXLENGTH 1000
#define TABSPACE 8

int get_line(char stored[]);
void entab(char stored[], char output[]);

int main()
{
    char stored[MAXLENGTH];
    char output[MAXLENGTH];
    while (get_line(stored) > 0) {
        entab(stored, output);
        printf("%s", output);
    }   
    return 0;
}

int get_line(char stored[]) 
{
    int i, c;
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

void entab(char stored[], char output[])
{
    int i, column = 0, k = 0, space_count = 0;
    for (i = 0; stored[i] != '\0'; ++i) {
        if (stored[i] == ' ') {
            ++space_count;
            ++column;

            if (column % TABSPACE == 0) {
                output[k++] = '\t';
                space_count = 0;
            }
        }
        else {
            while (space_count > 0) {
                output[k++] = ' ';
                --space_count;
            }

            output[k++] = stored[i];

            if (stored[i] == '\n')
                column = 0;
            else
                ++column;
        }
    }

    output[k] = '\0';
}

