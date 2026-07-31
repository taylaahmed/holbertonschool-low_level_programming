#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * main - check code
 * @argc: count arg
 * @argv: array arg
 *
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	int i;
	int a;
	int result = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{

		a = atoi(argv[i]);

		if (a == 0)
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			result += a;
		}
	}

	printf("%d\n", result);
	return (0);
}
