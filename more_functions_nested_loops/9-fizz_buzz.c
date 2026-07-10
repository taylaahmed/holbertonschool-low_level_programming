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
printf("FizzBuzz");
if (i != 100)
{
printf (" ");
}
}

else if (n == 0)
{
printf("Fizz");
if (i != 100)
{
printf (" ");
}
}

else if (b == 0)
{
printf("Buzz");
if (i != 100)
{
printf (" ");
}
}

else
{
printf("%d", i);
if (i != 100)
{
printf (" ");
}
}

}
printf("\n");
return (0);
}
