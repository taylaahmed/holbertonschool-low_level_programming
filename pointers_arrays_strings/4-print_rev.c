#include "main.h"

/**
* print_rev - check code
* @s: variable
*
*/

void print_rev(char *s)
{
int i;
int l = 0;

while (s[l] != '\0')
{
l++;
}
i = l;

while (i != 0)
{
_putchar(s[i]);
i--;
}
_putchar('\n');
}
