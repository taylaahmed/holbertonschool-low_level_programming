#include <stdio.h>
/**
* main - Entry point
*
*
* Return: Always 0 (Success) 
*/

int main(void)
{
char c;
int i;
long int l;
long long int e;
float f;

printf("Size of char: %d byte(s)\n", (int)sizeof(c));
printf("Size of int: %d byte(s)\n", (int)sizeof(i));
printf("Size of long int: %d byte(s)\n", (int)sizeof(l));
printf("Size of long long int: %d byte(s)\n", (int)sizeof(e));
printf("Size of float: %d byte(s)\n", (int)sizeof(f));

return (0);
}
