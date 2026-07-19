#include "main.h"

/*
* _atoi - check the code
* @*s: char var
* Return: 
*/

int _atoi(char *s)
{
int i = 0;
int n = 0;
int m = 1;

    while (s[i] != '\0')
    {
        if (s[i] == '-')
            m *= -1;

        if (s[i] >= '0' && s[i] <= '9')
            break;

        i++;
    }

    while (s[i] >= '0' && s[i] <= '9')
    {
        n = n * 10 + (s[i] - '0');
        i++;
    }

    return (n * m);
}
