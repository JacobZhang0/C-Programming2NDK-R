#include <stdio.h>
/* count characters in input; 1st version */
int main()
{
    int c, blanks, tabs, nl;

    nl = 0;
    tabs = 0;
    blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') 
            ++nl;
        if (c == '\t') 
            ++tabs;
        if (c == ' ') 
            ++blanks;
    }

    printf("newlines: %d\n", nl);
    printf("tabs: %d\n", tabs);
    printf("blanks: %d\n", blanks);
}