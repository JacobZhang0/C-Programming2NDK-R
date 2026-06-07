#include <stdio.h>

int main()
{
    int c, count;
    count = 0;

    while ((c = getchar()) != EOF) {
        if ((c == ' ') || (c == '\n') || (c == '\t')){
            for (int i = 0; i < count; i++) {
                printf("|");
            }
            printf("\n");
            count = 0;
        }
        if ((c != '\t') && (c != '\n') && (c != ' ')) {
            ++count;
        }
    }
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("|");
        }
        printf("\n");
    }
}