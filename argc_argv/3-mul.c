#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check code
 * @argc: arg count
 * @argv: arg array
 *
 * Return: 1 or 0
 */

int main(int argc, char *argv[])
{
	int a;
	int b;

	if (argc == 1 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", (a * b));
	return (0);
}
