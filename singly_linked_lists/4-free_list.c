#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - free contents of list
 * @head: pointer to first node in list
 *
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *delete_next;

	while (head != NULL)
	{
		delete_next = head->next;
		free(head->str);
		free(head);
		head = delete_next;
	}

	free(head);
}
