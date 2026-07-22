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
int i = 0;
if (grid[i] == NULL)
{
for (i = 0; i < height; i++)
	free(grid[i]);
}

if (grid == NULL)
	free(grid);

}
