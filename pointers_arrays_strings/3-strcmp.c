#include "main.h"

/**
* _strcmp - check code
* @s1: var 1
* @s2: var 2
*
* Return: value
*/

int _strcmp(char *s1, char *s2)
{
int n = 0;

while (s1[n] == s2[n] && s1[n] != '\0')
{
n++;
}
if (s1[n] != s2[n])
{
return (s1[n] - s2[n]);
}
return (0);
}
