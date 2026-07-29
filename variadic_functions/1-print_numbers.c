#include "variadic_functions.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - check code
 * @separator: ", "
 * @n: number of arguments
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list print;
	unsigned int i;

	va_start(print, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(print, int));

		if (i < (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	va_end(print);

	printf("\n");

}
