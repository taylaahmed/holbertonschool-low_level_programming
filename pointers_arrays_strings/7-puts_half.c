#include "main.h"

/**
* puts_half - check code
* @*str: var
*/

void puts_half(char *str)
{
int l = 0;
int h;

while (str[l] != '\0')
{
l++;
}
h = (l + 1)/2;

while (str[h] != '\0')
{
_putchar(str[h]);
h++;
}
_putchar('\n');
}
