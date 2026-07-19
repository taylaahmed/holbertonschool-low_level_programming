#include "main.h"

/**
* _strcat - check code
* @dest: var
* @src: var
* @n: int var
*
* Return: string of dest
*/

char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int l = 0;

while (dest[i] != '\0')
{
i++;
}

while (src[l] != '\0' && l < n)
{
dest[i] = src[l];
i++;
l++;
}

return (dest);
}
