#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - setting the nodes of a hash table
 * @ht: the table
 * @key: where in the array
 * @value: the stored value within the node
 *
 * Return: 1 or 0
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *current;
    char *new_value;
    int i = 0;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);
    index = key_index((unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            new_value = strdup(value);
            if (new_value == NULL)
                return (0);

            free(current->value);
            current->value = new_value;
            return (1);
        }
        current = current->next;
    }

    /* Create a new node */

    i = create_new_node(ht, key, value);

    return (i);
}

/**
 * create_new_node - creating a new node
 * @ht: the whole hash table thing
 * @value: the value being stored within node value
 * @key: the code at which the node is being stored
 *
 * Return: 1 or 0 to show success/failiure
 */

int create_new_node(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node;
    unsigned long int index;

    index = key_index((unsigned char *)key, ht->size);

    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
