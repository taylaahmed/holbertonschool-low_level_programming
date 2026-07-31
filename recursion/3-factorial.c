#include "main.h"

/**
 * factorial - find the factorial value of n through recursion
 * @n: the given value
 *
 * Return: value of n factorial, -1 or 1
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n > 0)
	{
		return (n * (factorial(n - 1)));
	}

	return (1);
}
