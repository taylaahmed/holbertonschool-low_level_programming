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
int n;

for (i = 0; haystack[i] != '\0'; i++)
{
n = 0;
while (needle[n] != '\0' && haystack[i + n] == needle[n])
{
n++;
}

if (needle[n] == '\0')
{
return (&haystack[i]);
}

}
return (NULL);
}
