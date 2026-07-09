#include "main.h"

/**
 * print_diagonal - check the code
 * @n: check int
 *
 * Return: void.
 */

void print_diagonal(int n)
{
int i = 0;
int b = 0;

if (n <= 0)
{
_putchar('\n');
}

for (i = 0; i < n; i++)
{
for (b = 0; b < i; b++)
{
_putchar(' ');
}
_putchar('\\');
_putchar('\n');
}
}
