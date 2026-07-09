#include "main.h"

/**
 * jack_bauer - check the code
 *
 *
 * Return: Always 0.
 */

void jack_bauer(void)
{
int i = 0;
int n = 0;

for (n = 0; n < 24; n++)
{
for (i = 0; i < 60; i++)
{
_putchar((n / 10) + '0');
_putchar((n % 10) + '0');
_putchar(':');
_putchar((i / 10) + '0');
_putchar((i % 10) + '0');
_putchar('\n');
}
}

}
