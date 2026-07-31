#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

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
	int n;
	int a;
	int result = 0;
	char *str;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		str = argv[i];
		for (n = 0; str[n] != '\0'; n++)
		{
			if (str[n] < '0' || str[n] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		a = atoi(argv[i]);
		result += a;
	}

	printf("%d\n", result);
	return (0);
}
