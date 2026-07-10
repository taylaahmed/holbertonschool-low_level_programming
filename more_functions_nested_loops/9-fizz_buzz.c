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

if (i % 3 == 0 && i % 5 == 0)
{
printf("FizzBuzz ");
}

if (i % 3 == 0)
{
printf("Fizz ");
}

if (i % 5 == 0)
{
printf("Buzz ");
}

else
{
printf("%d ", i);
}
}
printf("\n");
return (0);
}
