#include "main.h"
#include <stdlib.h>

/**
* malloc_checked - allocates to memory using malloc
* @b: unsigned integer variable
*
* Return: Pointer value
*/

void *malloc_checked(unsigned int b)
{
void  *mem;

mem = malloc(b);
if (mem == NULL)
	exit(98);


return (mem);
}
