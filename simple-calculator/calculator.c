#include <stdio.h>

/**
* main - function of quit calc
*
*
* Return: 0
*/

int main(void)
{
int n = 0; 

printf("1) Add\n");
printf("2) Subtract\n");
printf("3) Multiply\n");
printf("4) Divide\n");
printf("0) Bye\n");

printf("Choice: ");
scanf("%d", &n);

if (n == 0)
{
printf("Bye!\n");

return (0);
}

}
