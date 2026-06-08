#include <stdio.h>

// Didn't allow arrays yet

int main() 
{
    int a, b, c, d, e, f, g;
    a = b = c = d = e = f = g = 0;
    int input;
    while ((input = getchar()) != EOF) {
        if (input == 'a') {
            ++a;
        }
        if (input == 'b') {
            ++b;
        }
        if (input == 'c') {
            ++c;
        }
        if (input == 'd') {
            ++d;
        }
        if (input == 'e') {
            ++e;
        }
        if (input == 'f') {
            ++f;
        }
        if (input == 'g') {
            ++g;
        }
    }
    printf("a:%d\nb:%d\nc:%d\nd:%d\ne:%d\nf:%d\ng:%d\n", a, b, c, d, e, f, g);
}