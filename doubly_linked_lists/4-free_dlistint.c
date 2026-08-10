#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_dlistint - freeing
 * @head: the first node
 *
 * Return: nothing it is freed
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *delete_next;

	while (head != NULL)
	{
		delete_next = head->next;
		free(head);
		head = delete_next;
	}

	free(head);
}
