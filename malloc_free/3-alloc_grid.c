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
int **grid; 
int w;
int h;

while (width <= 0 || height <= 0)
return (NULL);

grid = malloc(height * sizeof(int *));
if (grid == NULL)
return (NULL);

for (w = 0; w < height; w++)
{
grid[w] = malloc(width * sizeof(int));
if (grid[w] == NULL)
return (NULL);
}

for (h = 0; h < height; h++)
{
for (w = 0; w < width; w++)
{
grid[h][w] = 0;
}
}
return (grid);
}
