#include "main.h"

/**
* _strncpy - check code
* @*dest: var
* @*src: var
* @n: int var
*
* Return: string of dest
*/

char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

while (src[i] != '\0' && i < n)
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
