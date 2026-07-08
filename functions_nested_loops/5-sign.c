#include "main.h"
/**
* print_sign - print plus, zero, negetive
* @n: character to check
*
* Return: depending on n value
*/
int print_sign(int n)
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar('0');
return (0);
}
else
{
_putchar('-');
return (-1);
}
}
