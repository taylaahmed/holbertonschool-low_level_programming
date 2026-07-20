#include "main.h"
#include <stdio.h>

/**
* print_array - check code
* @a: int var
* @n: int var
*/

void print_array(int *a, int n)
{
int i = 0;

for (i = 0; i < n; i++)
{
printf("%d", a[i]);

if (i != n)
{
printf(", ");
}
}
printf("\n");
}
