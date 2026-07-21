#include "main.h"
#include <stdlib.h>

/**
* _strdup - check code
* @str: var
*
* Return: array duplicate
*/

char *_strdup(char *str)
{
char *array;
int i = 0;
int n;

	while (str[i] != '\0')
	{
	i++;
	}

	array = malloc(i * sizeof(char));

	if (str == 0 || array == NULL)
	{
	return (NULL);
	}
	for (n = 0; n < i; n++)
	{
	array[n] = str[n];
	}

return (array);
}
