#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * add_node - change the order of the existing nodes
 * @head: pointer to firt node
 * @str: the string to place in
 *
 * Return: temp
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;
	int i = 0;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);

	temp->str = strdup(str);
	while (str[i] != '\0')
		i++;
	temp->len = i;
	temp->next = *head;

	*head = temp;

	return (temp);
}
