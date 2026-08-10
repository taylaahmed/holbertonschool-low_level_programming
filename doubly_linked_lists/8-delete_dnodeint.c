#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 *
 *
 *
 *
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *before;
	dlistint_t *current;
	dlistint_t *after;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	
	if (index == 0)
	{
		current = *head;
		*head = current->next;

		if (*head != NULL)
			(*head)->prev = NULL;

        	free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (1);

	before = current->prev;
	after = current->next;

	before->next = after;
	if (after != NULL)
		after->prev = before;

	free(current);

	return (1);
}

