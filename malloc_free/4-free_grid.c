#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
* free_grid - check code
* @grid: array
* @height: the 'row' variable
*
* Return: NULL
*/

void free_grid(int **grid, int height)
{
int i;

for (i = 0; i < height; i++)
free(grid[i]);

free(grid);

}
