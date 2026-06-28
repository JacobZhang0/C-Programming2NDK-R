#include <stdio.h>

void str_cat(char *, char *);

int main(void)
{
    return 0;
}

void str_cat(char *s, char *t)
{
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;
}