#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* key_index - return value at key index
* @key: number assigned to array
* @size: size of array
*
* Return: Always EXIT_SUCCESS.
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
