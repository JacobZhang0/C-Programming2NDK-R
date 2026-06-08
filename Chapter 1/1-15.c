#include <stdio.h>

int c_to_f(int celsius);

int main()
{
    printf("Celsius\t\tFahrenheit\n--------------------------------\n");
    for (int i = 0; i <= 300; i+=20) {
        printf("%d\t\t%d\n", i, c_to_f(i));
    }
    return 0;
}

int c_to_f(int celsius)
{
    return celsius * 9 / 5 + 32;
}