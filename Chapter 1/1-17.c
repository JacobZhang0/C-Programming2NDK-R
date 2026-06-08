#include <stdio.h>

#define MAXLENGTH 1000

int length_check(char line[], int lim);

int main() 
{
    int len;
    char stored[MAXLENGTH];
    while ((len = length_check(stored, MAXLENGTH)) > 0) 
        if (len > 80) 
            printf("%s", stored);
        
    

}

int length_check(char line[], int lim) 
{
    int c, len = 0, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            line[i] = c;
        }
        ++len;
    }

    if (c == '\n') {
        ++len; 
        if (i < lim - 1) {
            line[i] = c;
        }
        ++i;
    }
    if (i < lim)
        line[i] = '\0';
    else
        line[lim-1] = '\0';
    return len;
}