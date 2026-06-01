#include <stdio.h>

int main()
{
    float fahr, celsius;
    float step, upper, lower;

    upper = 300;
    lower = 0;
    step = 20;

    celsius = lower;
    printf("Celsius\t\tFahrenheit\n--------------------------------\n");
    while (celsius <= upper) {
        fahr = celsius * 9.0/5.0 + 32;
        printf("%5.0f\t\t%7.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

}