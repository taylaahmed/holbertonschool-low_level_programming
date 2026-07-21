#include "main.h"
#include <stdlib.h>

/**
* str_concat - check code
* @s1: char var 1
* @s2: char var 2
*
* Return: NULL or string array
*/

char *str_concat(char *s1, char *s2)
{
	int c1 = 0;
	int c2 = 0;
	int size = 0;
	int i;
	int n = 0;
	char *array;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (s1[c1] != '\0')
		c1++;

	while (s2[c2] != '\0')
		c2++;
	size = c1 + c2 + 2;

	array = malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < c1; i++)
		array[i] = s1[i];

	for (i = c1; i < size; i++)
	{
		array[i] = s2[n];
		n++;
	}

	return (array);
}
