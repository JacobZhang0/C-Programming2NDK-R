#include <stdio.h>

#define TABSPACE 8
#define MAXLENGTH 1000

void detab(char stored[], char output[]);
void entab(char stored[], char output[]);
int get_line(char stored[]);

int main(int argc, char *argv[]) 
{
    char stored[MAXLENGTH];
    char output[MAXLENGTH];
    int c;
    while (--argc > 0 && (*++argv)[0] == '-') {
        c = (*argv)[1];
        switch (c) {
        case 'e':
            while (get_line(stored) > 0) {
                entab(stored, output);
                printf("%s", output);
            }
            break;
        case 'd':
            while (get_line(stored) > 0) {
                detab(stored, output);
                printf("%s", output);
            }
            break;
        default:
            printf("Illegal operation\n");
            return -1;
        }
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

void detab(char stored[], char output[])
{
    int i, column = 0, k = 0;
    for (i = 0; stored[i] != '\0'; ++i) {
        if (stored[i] == '\n') {
            output[k++] = '\n';
            column = 0;
        }
        else if (stored[i] == '\t') {
            int spaces = TABSPACE - (column % TABSPACE);

            for (int j = 0; j < spaces; ++j) {
                output[k++] = ' ';
                ++column;
            }
        }
        else {
            output[k++] = stored[i];
            ++column;
        }
    }

    output[k] = '\0';
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