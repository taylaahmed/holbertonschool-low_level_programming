#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
* create_array - check code
* @size: int var
* @c: char var
*
* Return: NULL or array
*/
char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;

array = malloc(size * sizeof(char));

if (size == 0 || array == NULL)
{
return (NULL);
}

	for (i = 0; i < size; i++)
	{
	array[i] = c;
	}

return (array);
}
