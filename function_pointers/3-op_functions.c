#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - addition
 * @a: int 1
 * @b: int 2
 *
 * Return: a + b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtraction
 * @a: int 1
 * @b: int 2
 *
 * Return: a - b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply
 * @a: int 1
 * @b: int 2
 *
 * Return: a * b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division
 * @a: int 1
 * @b: int 2
 *
 * Return: a / b
 */

int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - division remainder
 * @a: int 1
 * @b: int 2
 *
 * Return: a / b remainder (a % b)
 */

int op_mod(int a, int b)
{
	return (a % b);
}
