#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check code
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 0)
		return (0);

	printf("%s\n", argv[0]);
	return (0);
}
