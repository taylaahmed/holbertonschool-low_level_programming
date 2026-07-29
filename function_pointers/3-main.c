#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - check code
 * @arcg: count number of arguments
 * @argv: input array
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a;
	int b;
	char *op;
	int (*o)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2];

	o = get_op_func(op);

	if (o == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '%' || argv[2][0] == '/') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", (*o)(a, b));
	return (0);
}
