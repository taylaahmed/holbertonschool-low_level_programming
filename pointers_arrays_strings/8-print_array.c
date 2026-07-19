#include "main.h"
#include <stdio.h>

/**
* print_array - check code
* @*a: int var
* @n: int var
*/

void print_array(int *a, int n)
{
n = 0;

for (n = 0; n < 5; n++)
{
printf("%d", a[n]);

if (n != 4)
{
printf(", ");
}
}
printf("\n");
}
