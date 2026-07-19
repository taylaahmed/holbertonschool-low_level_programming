#include "main.h"

/**
* cap_string - check code
* @a: char car
*
* Return: value of a
*/

char *cap_string(char *a)
{
int n = 0;

for (n = 0; a[n] != '\0'; n++)
{
if (a[n - 1] >= 32 && a[n - 1] <= 47)
{
if (a[n] >= 'a' && a[n] <= 'z')
{
a[n] -= 32;
}
}
if (a[n - 1] == '\n' || a[n - 1] == '\t')
{
if (a[n] >= 'a' && a[n] <= 'z')
{
a[n] -= 32;
}
}
}
return (a);
}
