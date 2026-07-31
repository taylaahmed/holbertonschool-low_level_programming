#include "main.h"

/**
 * _pow_recursion - check code
 * @x: int 1
 * @y: int 2
 *
 * Return: powers to value
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
