#include "main.h"

/**
 * _strlen_recursive - check code
 * @s: pointer to string
 *
 * Return: 0 or length of string
 */

int _strlen_recursion(char *s)
{

	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}

	return (0);
}
