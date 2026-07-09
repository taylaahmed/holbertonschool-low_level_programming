#include "main.h"

/**
 * print_last_digit - of numbers in function
 * @i: character to check for
 *
 * Return: value of last
 */

int print_last_digit(int i)
{
int last = i % 10;
if (i < 0)
{
(last = -last);
}
_putchar(last + '0');
return (last);
}
