#include "main.h"

/**
 * support - check code
 * @n: the assigned number
 * @root: root value
 *
 * Return: value of root
 */

int support(int n, int root)
{
	if ((root * root) > n)
	{
		return (-1);
	}
	if ((root * root) == n)
	{
		return (root);
	}

	return (support(n, root + 1));
}

/**
 * _sqrt_recursion - check code
 * @n: the assigned number
 *
 * Return: value of root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (support(n, 0));
}
