#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* init_dog - check the code
* @d: struct dog
* @name: char name of dog
* @age: age of dog (float)
* @owner: owners name
*
* Return: none
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
