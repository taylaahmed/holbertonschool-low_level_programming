#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - print the content of hash table
 * @ht: hash table
 *
 * Return: nothing void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	unsigned long int size;
	unsigned long int i;
	char *sep;

	if (ht == NULL)
	{
		return;
	}

	size = ht->size;
	sep = "";

	printf("{");

	for (i = 0; i < size; i++)
	{
		current = ht->array[i];

		while (current != NULL)
		{
			printf("%s", sep);
			printf("'%s': ", current->key);
			printf("'%s'", current->value);
			current = current->next;
			sep = ", ";
		}
	}
	printf("}\n");
}
