#include <stdio.h>

char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
int strn_cmp(char *, char *, int);

int main(void)
{
    return 0;
}

char *strn_cpy(char *s, char *ct, int n)
{
    char *originalpointer = s;

    while (n-- > 0 && (*s++ = *ct++) != '\0')
        ;

    while (n-- > 0)
        *s++ = '\0';

    return originalpointer;
}

char *strn_cat(char *s, char *ct, int n)
{
    char *original = s;

    while (*s)
        s++;

    while (n-- > 0 && *ct != '\0')
        *s++ = *ct++;

    *s = '\0';

    return original;
}

int strn_cmp(char *cs, char *ct, int n)
{
    for (;n > 0; cs++, ct++, n--) {
        if (*cs == *ct) {
            return *cs - *ct;
        }
        else if (*cs == '\0') {
            return 0;
        }
    }
    return 0;
}
