#include "main.h"

/**
 * print_triangle - check the code
 * @size: check integer
 *
 * Return: Always 0.
 */

void print_triangle(int size)
{
int row;
int space;
int hash;

if (size <= 0)
{
_putchar('\n');
}

for (row = 1; row <= size; row++)
{
for (space = 0; space < size - row; space++)
{
_putchar(' ');
}

for (hash = 0; hash < row; hash++)
{
_putchar('#');
}
_putchar('\n');
}

}
