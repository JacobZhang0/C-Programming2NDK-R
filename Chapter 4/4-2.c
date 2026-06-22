#include <stdio.h>
#include <ctype.h>
#include <math.h>


double atof(char s[]);

int main(void) 
{

    printf("%.10lf", atof("123.45e-6"));
    return 0;
}

double atof(char s[])
{
    int i, sign, len, exponsign, exponval;
    double val, power;

    for (len = 0; s[len] != '\0'; len++) {
        ;
    }

    for (int i = 0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        exponsign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
            i++;

        for (exponval = 0; isdigit(s[i]); i++)
            exponval = 10 * exponval + (s[i] - '0');

        val = val * pow(10.0, exponsign * exponval);
    }
    return sign * val / power;
}