#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieve info from hash
 * @ht: my hash table
 * @key: where I want ot reteive info
 *
 * Return: the value at key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			if (current->value != 0)
				return (current->value);

			return (NULL);
		}

	current = current->next;
	}

	return (NULL);
}
