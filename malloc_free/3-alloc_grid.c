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

array = malloc(width * sizeof(int *));

	for (i = 0; i < width; i++)
		array = malloc(height * sizeof(int));

	for (i = 0; i < width; i++)
		{
		for (j = 0; j < height; j++)
		array[i][j] = 0;
		}
	return (array);

for (i = 0; i < width; i++)
free(array[i]);

free(array);

return (0);
}
