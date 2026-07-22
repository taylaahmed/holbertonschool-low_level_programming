#include "main.h"
#include <stdlib.h>

/**
* array_range - creates an array of integers
* @min: int variable
* @max: int variable
*
* Return: NULL or pointer of array
*/

int *array_range(int min, int max)
{
int size;
int *array;
int c;

if (min > max)
	return (NULL);

size = max - min + 1;

array = malloc(size *sizeof(int));

if (array == NULL)
	return (NULL);

for (c = 0; c < size; c++)
	array[c] = min + c;

return (array);
}
