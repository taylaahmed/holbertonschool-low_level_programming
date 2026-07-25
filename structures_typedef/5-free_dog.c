#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
* free_dog - write function to free
* @d: matrix info
*
* Return: none
*/

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->owner);
	free(d->name);

	free(d);
}
