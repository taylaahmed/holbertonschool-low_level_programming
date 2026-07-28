#include "function_pointers.h"
#include <stdlib.h>

/**
 * array_iterator - check code
 * @array: int array
 * @size: size of object in byte
 * @action: pointer to a function
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
