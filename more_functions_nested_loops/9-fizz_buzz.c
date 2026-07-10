#include <stdio.h>

/**
* main - check code
*
*
* Return: (0)
*/

int main(void)
{
int i = 1;

for (i = 1; i <= 100; i++)
{
int n = i % 3;
int b = i % 5;

if (n == 0 && b == 0)
{
printf("FizzBuzz ");
}

if (n == 0)
{
printf("Fizz ");
}

if (b == 0)
{
printf("Buzz ");
}

else if (b != 0 && n != 0)
{
printf("%d ", i);
}
}
printf("\n");
return (0);
}
