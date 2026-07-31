#include "main.h"

/**
 * support - check code
 * @n: number initial
 * @div: check divisability
 *
 * Return: 1 or 0
 */

int support(int n, int div)
{
	if (n % div == 0)
		return (0);
	else if (div >= n / 2)
		return (1);
	else
		return (support(n, div + 1));
}

/**
 * is_prime_number - check code
 * @n: intial number
 *
 * Return: 0 or 1
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (support(n, 2));
}
