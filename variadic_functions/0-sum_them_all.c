#include "variadic_functions.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * sum_them_all - check code
 * @n: unsigned constant int
 *
 * Return: 0 or n
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list va;
	unsigned int i = 0;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(va, n);

	while (i < n)
	{
		sum += va_arg(va, int);
		i++;
	}

	va_end(va);
	return (sum);
}
