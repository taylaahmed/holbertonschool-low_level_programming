#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - function that combines two strings
* @s1: char variable
* @s2: char variable
* @n: unsigned int var
*
* Return: Values of strings combined or NULL
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *combine;
unsigned int c = 0;
unsigned int i = 0;
unsigned int b = 0;

if (s1 == NULL || s2 == NULL)
	return (" ");

while (s1[c] != '\0')
	c++;

combine = malloc(c + n);

if (combine == NULL)
	return (NULL);


for (b = 0; s1[b] != '\0'; b++)
	combine[b] = s1[b];


for (i = 0; i <= n; i++)
{
	combine[b] = s2[i];
	b++;
}

combine[b] = '\0';

return (combine);
}
