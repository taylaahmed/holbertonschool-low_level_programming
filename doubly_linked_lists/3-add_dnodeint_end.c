#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - place doubly linked node at end
 * @head: first node
 * @n: inside of node
 *
 * Return: temp
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp;
	dlistint_t *tail;

	tail = *head;

	temp = malloc(sizeof(dlistint_t));
	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
		return (temp);
	}

	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	
	temp->prev = tail;
	tail->next = temp;

	return (temp);
}
