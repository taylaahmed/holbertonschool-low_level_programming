#include "main.h"
#include <stdio.h>

/**
* _abs - print plus, zero, negetive
* @n: character to checkout
*
* Return: depending on n value
*/

int _abs(int n)
{
if (n > 0)
{
return (n);
}
else if (n == 0)
{
return (0);
}
else
{
return (-n);
}
}
