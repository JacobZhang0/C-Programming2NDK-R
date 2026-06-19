#include <stdio.h>

void expand(char s1[], char s2[]);

int main(void)
{
    return 0;
}

void expand(char s1[], char s2[])
{
    int i = 0, j = 0;
    char c;

    if (s1[0] == '-') {
        s2[j++] = '-';
        i = 1;
    }

    for (; s1[i] != '\0'; i++) {

        c = s1[i];

        // messy but works
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && s1[i - 1] < s1[i + 1] && 
            ((s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && 
            s1[i + 1] >= 'a' && s1[i + 1] <= 'z') ||
             (s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' &&
              s1[i + 1] >= 'A' && s1[i + 1] <= 'Z') ||
             (s1[i - 1] >= '0' && s1[i - 1] <= '9' &&
              s1[i + 1] >= '0' && s1[i + 1] <= '9'))) {

            for (char k = s1[i - 1] + 1; k < s1[i + 1]; k++)
                s2[j++] = k;

        } else {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}