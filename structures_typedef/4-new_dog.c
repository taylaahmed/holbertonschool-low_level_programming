#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* new_dog - check code
* @name: name of dog
* @age: age of dog
* @owner: name of dog owner
*
* Return: dog_t or NULL
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	int c1 = 0;
	int c2 = 0;
	int i;
	int n;

	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name = malloc(c1 + 1);
	if (new_dog->name == NULL)
		return (NULL);

	new_dog->owner = malloc(c2 + 1);
	if (new_dog->owner == NULL)
		return (NULL);

	while (name[c1] != '\0')
		c1++;

	while (owner[c2] != '\0')
	c2++;

	for (i = 0; i <= c1; i++)
		new_dog->name[i] = name[i];

	for (n = 0; n <= c2; n++)
		new_dog->owner[n] = owner[n];

	new_dog->age = age;

	return (new_dog);
}
