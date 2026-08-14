#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * 
 * 
 * 
 */

void hash_table_delete(hash_table_t *ht)
{
    unsigned int size;
    unsigned int i;
    hash_node_t *current;
    hash_node_t *delete;

    if (ht == NULL)
    {
        return;
    }

    size = ht->size;

    for (i = 0; i < size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            delete = current;
            current = current->next;

            free(delete->key);
            free(delete->value);
            free(delete);
        }
    }

    free(ht->array);
    free(ht);
}
