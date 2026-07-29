#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_strings - check code
 * @separator: ", "
 * @n: number of arguments in list
 *
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arg;
	unsigned int i;
	char *string;

	va_start(arg, n);

	for (i = 0; i < n; i++)
	{
		string = va_arg(arg, char *);

		if (string != NULL)
			printf("%s", string);
		else
			printf("(nil)");

		if (i < (n - 1) && separator != 0)
			printf("%s", separator);
	}

	va_end(arg);

	printf("\n");
}
