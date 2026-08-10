#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - print the correct node
 * @head: first node
 * @index: the number
 *
 * Return: corresponding node to index
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{

	unsigned int n = 0;

	while (n < index)
	{
		head = head->next;
		n++;
	}

	return (head);
}
