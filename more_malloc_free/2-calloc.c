#include "main.h"
#include <stdlib.h>

/**
* _calloc - allocates memory to an array
* @nmemb: unsigned int var
* @size: unsigned int var
*
* Return: Return array(memory) or NULL
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
int *cal;
unsigned int i;

if (nmemb == 0 || size == 0)
	return (NULL);

cal = malloc(nmemb * size);

if (cal == NULL)
	return (NULL);

for (i = 0; i < nmemb; i++)
	cal[i] = 0;

return (cal);

}
