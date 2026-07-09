#include "main.h"

/**
 * times_table - prints the 9 times table
 *
 * Return: void
 */

void times_table(void)
{
int n;
int i;
int product;

for (n = 0; n <= 9; n++)
{
for (i = 0; i <= 9; i++)
{
product = n * i;

if (i != 0)
{
_putchar(',');
_putchar(' ');

if (product < 10)
_putchar(' ');

}

if (product >= 10)
{
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}
else
{
_putchar(product + '0');
}

}
_putchar('\n');
}
}
