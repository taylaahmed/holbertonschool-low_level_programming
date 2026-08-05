#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 *
 *
 *
 *
 */

size_t print_list(const list_t *h)
{
	int count = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)i\n");
		else
			printf("[%d] %s\n", current->len, current->str);
		current = current->next;
		count++;
	}
	return (count);
}
