#include "main.h"
#include <stddef.h>

/**
* _strpbrk - check code
* @s: var
* @accept: var
*
* Return: s only accept characters
*/

char *_strpbrk(char *s, char *accept)
{
int i;
int n;

for (i = 0; s[i] != '\0'; i++)
{
for (n = 0; accept[n] != '\0'; n++)
{
if (s[i] == accept[n])
{
return (&s[i]);
}
}
}
return (NULL);
}
