#include "main.h"

/**
* _strspn - check code
* @s: var
* @accept: var
*
* Return: string of dest
*/

unsigned int _strspn(char *s, char *accept)
{
int i;
int n;
int count = 0;
int found;

for (i = 0; s[i] != '\0'; i++)
{
found = 0;

for (n = 0; accept[n] != '\0'; n++)
{
if (s[i] == accept[n])
{
found = 1;
break;
}
}

if (found == 0)
break;

count++;
}

return (count);
}
