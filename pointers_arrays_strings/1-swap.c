#include "main.h"

/**
* swap_int - swap integers for *a and *b
* @*a: variable 1
* @*b: variable 2
*/

void swap_int(int *a, int *b)
{
int m;

m = *a;
*a = *b;
*b = m;
}
