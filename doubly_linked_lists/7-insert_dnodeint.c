#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserting
 * @h: pointer to head
 * @index: where to add
 * @n: value
 *
 * Return: new
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *current;
	dlistint_t *after;
	unsigned int i = 0;
	
	if (h == NULL)
		return (NULL);

	current = *h;

	if (idx == 0)
	{
		new = malloc(sizeof(dlistint_t));
		if (new == NULL)
			return (NULL);

		new->n = n;
		new->prev = NULL;
		new->next = *h;

		if (*h != NULL)
			(*h)->prev = new;

		*h = new;
		return (new);
	}
	
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	after = current->next;
	new->prev = current;
	new->next = after;
	current->next = new;

	if (after != NULL)
		after->prev = new;

	return (new);
}
