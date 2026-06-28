#include <stdio.h>

int strend(char *, char *);

int main(void)
{
    char text[] = "My name is Jacob.";
    char piece[] = "Jacob";
    printf("%d", strend(text, piece));
    return 0;
}

int strend(char *s, char *t)
{

    char *t_start = t;

    while (*s != '\0')
        s++;
    while (*t != '\0')
        t++;

    for (;; --s, --t) {
        if (*s != *t)
            return 0;
        if (t_start == t)
            break;
    }

    return 1;

}