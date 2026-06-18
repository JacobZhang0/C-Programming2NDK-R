#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) 
{
    char s1[] = "Hello, World!";
    char s2[] = "Helo, W";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++) {
        for (j = 0; s1[j] != '\0'; j++) {
            if (s2[i] == s1[j]) {
                for (k = j; s1[k] != '\0'; k++) {
                    s1[k] = s1[k+1];
                }
                j--;
            }
        }
    }
}