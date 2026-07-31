#include "main.h"
#include <stddef.h>

/**
 * _print_rev_recursion - check code
 * @s: pointer to string
 *
 * Return: void
 */

void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
	else if (s == NULL)
	{
	_putchar('\n');
	}
}
