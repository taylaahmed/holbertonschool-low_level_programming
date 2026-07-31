#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * main - check code
 * @argc: count arguments
 * @argv: array arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
