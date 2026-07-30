#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check code
 * @argc: argument count
 * @argv: argument array
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argv == NULL)
		return (0);

	printf("%d\n", (argc - 1));
	return (0);
}
