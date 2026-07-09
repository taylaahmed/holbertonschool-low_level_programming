#include "main.h"
#include <stdio.h>

/**
* _isdigit - print 1 if Capital print 0 if lowercase
* @c: integer
*
* Return: 0 or 1
*/

int _isdigit(int c)
{
if (c >= '0' && c <= '9')
{
return (1);
}
else
{
return (0);
}
}
