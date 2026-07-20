#include "main.h"

/**
* _memcpy - change 0x00 with 0x01
* @src: var
* @dest: var
* @n: var
* Return: value of array dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{

unsigned int i;

for (i = 0; i < n; i++)
{
dest[i] = src[i];
}

return (&dest[i]);
}
