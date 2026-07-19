#include "main.h"

/**
* _strcpy - check code
* @*dest: var char
* @*src: var char
*
* Return: value of the pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++; 
}
dest[i] = '\0';
return (dest);
}
