#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Minimum value of a unsigned char: %d\n", 0);
    printf("Maximum value of a unsigned char: %d\n", UCHAR_MAX);
    printf("Minimum value of a signed char: %d\n", SCHAR_MIN);
    printf("Maximum value of a signed char: %d\n", SCHAR_MAX);

    printf("Minimum value of a unsigned short: %d\n", 0);
    printf("Maximum value of a unsigned short: %d\n", USHRT_MAX);
    printf("Minimum value of a signed short: %d\n", SHRT_MIN);
    printf("Maximum value of a signed short: %d\n", SHRT_MAX);

    printf("Minimum value of a unsigned int: %d\n", 0);
    printf("Maximum value of a unsigned int: %u\n", UINT_MAX);
    printf("Minimum value of a signed int: %d\n", INT_MIN);
    printf("Maximum value of a signed int: %d\n", INT_MAX);

    printf("Minimum value of a unsigned long: %u\n", 0);
    printf("Maximum value of a unsigned long: %lu\n", ULONG_MAX);
    printf("Minimum value of a signed long: %ld\n", LONG_MIN);
    printf("Maximum value of a signed long: %ld\n", LONG_MAX);

    printf("Minimum floating point number: %.2f\n", FLT_MIN);
    printf("Maximum floating point number: %.2f\n", FLT_MAX);

    printf("Minimum double floating point number: %.2lf\n", DBL_MIN);
    printf("Maximum double floating point number: %.2lf\n", DBL_MAX);

    return 0;
}