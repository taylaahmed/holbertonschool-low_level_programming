#include "main.h"
#include <stdlib.h>

/**
* alloc_grid - returns a pointer to a 2 dimensional array of integers
* @width: int var 1
* @height: int var 2
*
* Return: NULL or array
*/

int **alloc_grid(int width, int height)
{
int **array;
int i;
int j;

	if (width <= 0 || height <= 0)
		return (NULL);

array = malloc(height * sizeof(int *));

if (array == NULL)
	{
	for (i = 0; i < height; i++)
	free(array[i]);

	free(array);
	return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		array[i] = malloc(width * sizeof(int));

	if (array[i] == NULL)
	{
	while (i > 0)
	{
		i--;
	free(array[i]);

	free(array);
	return (NULL);
	}
	}
}

for (i = 0; i < height; i++)
		{
		for (j = 0; j < width; j++)
		array[i][j] = 0;
		}
return (array);
}
