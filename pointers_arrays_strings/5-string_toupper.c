#include "main.h"

/**
* string_toupper - check code
* @*a: char var
*
* Return: array a
*/

char *string_toupper(char *a)
{
int n = 0;

for (n = 0; a[n] != '\0'; n++)
{
if (a[n] >= 'a' && a[n] <= 'z')
{
a[n] -= 32;
}
}
return (a);
}
