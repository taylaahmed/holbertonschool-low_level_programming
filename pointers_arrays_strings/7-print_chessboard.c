#include "main.h"

/**
* print_chessboard - check code
* @a: var
*
* Return: no return void
*/

void print_chessboard(char (*a)[8])
{
int row;
int col;
char c;

for (row = 0; row < 8; row++)
{
for (col = 0; col < 8; col++)
{
c = a[row][col];
_putchar(c);
}
_putchar('\n');
}
}
