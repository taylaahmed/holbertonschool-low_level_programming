#include "main.h"
#include <stddef.h>

/**
* _strstr - check code
* @haystack: var
* @needle: var
*
* Return: s only accept characters
*/

char *_strstr(char *haystack, char *needle)
{
int i;
int n = 0;

for (i = 0; haystack[i] != '\0'; i++)
{
while (needle[n] != '\0' && haystack[i + n] == needle[n])
{
return (&needle[n]);
}
}
return (NULL);
}
