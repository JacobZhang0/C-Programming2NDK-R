#include <stdio.h>

void escape(char s[], char t[]);

int main(void) 
{
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    char c;

    for (i = j = 0; t[i] != '\0'; i++) {
        c = t[i];

        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
    }

    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    char c;

    for (i = j = 0; t[i] != '\0'; i++) {
        c = t[i];

        if (c == '\\') {
            switch (t[i + 1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                default:
                    s[j++] = '\\';
                    break;
            }
        } else {
            s[j++] = c;
        }
    }

    s[j] = '\0';
}