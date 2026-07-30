#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 *
 *
 *
 *
 *
 */

void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	unsigned int j = 0;
	char *sep = "";
	
	print_t types[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};
	
	va_start(args, format);

	while (format != NULL && format[i] != '\0') 
	{
		j = 0;

		while (types[j].type != NULL) 
		{
			if (format[i] == types[j].type[0])
			{
				printf("%s", sep);
				types[j].f(args);
				sep = ", ";
				break;
			}
		j++;
		}
	i++;
	}

	va_end (args);
	printf("\n");

}

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

void print_string(va_list args)
{
	char *a;
	a = va_arg(args, char *);
		
	if (a == NULL)
		printf("(nil)");
	
	printf("%s", a);
}
