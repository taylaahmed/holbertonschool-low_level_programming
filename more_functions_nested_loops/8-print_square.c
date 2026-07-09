#include "main.h"

/**
 * print_square - check the code
 * @size: integer to check for
 *
 * Return: void
 */

void print_square(int size)
{
int i = 0;
int n = 0;

if (size <= 0)
{
_putchar('\n');
}

for (i = 0; i < size; i++)
{
for (n = 0; n < size; n++)
{
_putchar('#');
}
_putchar('\n');
}

}
