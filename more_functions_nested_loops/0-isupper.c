#include "main.h"
#include <stdio.h>

/**
* _isupper- print 1 if Capital print 0 if lowercase
* @c: integer
*
* Return: 0 or 1
*/

int _isupper(int c)
{
if (c >= 'A' && c <= 'Z')
{
return (1);
}
else
{
return (0);
}
}
