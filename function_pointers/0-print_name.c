#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - check code
 * @name: char array
 * @f: pointer to function
 *
 * Return: none
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
