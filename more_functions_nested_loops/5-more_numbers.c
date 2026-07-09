#include "main.h"

/**
 * more_numbers - check the code
 *
 * Return: void
 */

void more_numbers(void)
{
int i = 0;
int n = 0;
for (n = 0; n < 10; n++)
{
for (i = 0; i < 15; i++)
{
if (i >= 10)
{
_putchar((i / 10) + '0');
}
_putchar((i % 10) + '0');
}
_putchar('\n');
}
}
