#include <stdio.h>

/**
* main - functions of a calculator (addition, subtration, multiplication and division)
*
*
* Return: 0
*/

int main(void)
{
	int n = 0; 
	int a = 0;
	int b = 0;
	int r;
	double d;

	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Bye\n");

	printf("Choice: ");
	scanf("%d", &n);

	while (n != 0)
	{
		if (n < 0 || n >= 5)
		{
		printf("Invalid choice\n");
		}

		if (n == 1)
		{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		r = (a + b);
		printf("Result: %d\n", r);
		}

		if (n == 2)
		{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		r = (a - b);
		printf("Result: %d\n", r);
		}

		if (n == 3)
		{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		r = (a * b);
		printf("Result: %d\n", r);
		}

		if (n == 4)
		{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		if (b == 0)
		{
		printf("Error: division by zero\n");
		}

		else
		{
		d = ((float)a / b);
		printf("Result: %.1f\n", d);
		}
		}

		printf("Choice: ");
		scanf("%d", &n);
		}

	printf("Bye!\n");

	return (0);


}
