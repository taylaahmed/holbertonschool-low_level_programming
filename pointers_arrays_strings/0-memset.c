#include "main.h"

/**
* _memset - change 0x00 with 0x01
* @s: var
* @b: var
* @n: var
* Return: value of array s
*/

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i <= n - 1; i++)
{
s[i] = b;
}

return (&s[i]);
}
