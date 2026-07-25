#ifndef DOG_H
#define DOG_H

/**
* struct dog - defining dog characteristics
* @name: name of dog
* @age: age of dog
* @owner: name of dog owner
*
* Return - none
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
