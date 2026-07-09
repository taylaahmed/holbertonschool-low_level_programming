#include "main.h"

/**
 * times_table - check the code
 *
 *
 * Return: void
 */

void times_table(void)
{
int n = 0;
int i = 0;
int product = 0;

for (n = 0; n <= 9; n++)
{
for (i = 0; i <= 9; i++)
{
product = n * i;

if (product >= 10)
{
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}
else
{
_putchar(product + '0');

}
if (i != 9 && product < 10 && i != 0)
{
_putchar(',');
_putchar(' ');
_putchar(' ');
}
else if (i != 9)
{
_putchar(',');
_putchar(' ');
}
}
_putchar('\n');
}
}
