#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(void)
{
    char hex[] = "0xF";
    printf("%d\n", htoi(hex));
    return 0;
}

int htoi(char s[])
{
    int conversion = 0;
    int i;
    int value;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {

        for (i = 2; s[i] != '\0'; ++i) {

            if (s[i] >= '0' && s[i] <= '9')
                value = s[i] - '0';

            else if (s[i] >= 'A' && s[i] <= 'F')
                value = s[i] - 'A' + 10;

            else if (s[i] >= 'a' && s[i] <= 'f')
                value = s[i] - 'a' + 10;

            else
                break;

            conversion = 16 * conversion + value;
        }
    }

    return conversion;
}