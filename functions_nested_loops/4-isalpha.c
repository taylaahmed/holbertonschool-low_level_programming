#include "main.h"

/**
 * _isalpha - print 1 if it is a character value
 *
 * Return: Always 0.
 */

int _isalpha(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else if (c >= 'A' && c <= 'Z')
{
return (1);
}
else
{
return (0);
}
}
