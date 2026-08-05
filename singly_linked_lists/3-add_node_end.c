#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node_end - check code
 * @head: pointer to a pointer
 * @str: printed
 *
 * Return: temp
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp;
	list_t *tail;
	int i = 0;

	tail = *head;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);

	temp->str = strdup(str);
	while (str[i] != '\0')
		i++;
	temp->len = i;
	temp->next = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return (temp);
	}

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	tail->next = temp;
	return (temp);
}
