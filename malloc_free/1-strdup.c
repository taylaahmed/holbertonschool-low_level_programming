#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
* _strdup - check code
* @str: var
*
* Return:
*/

char *_strdup(char *str)
{
int c = 0;
int i;
char *array;

if (str == NULL)
{
return (NULL);
}
while (str[c] != 0)
{
c++;
}

array = malloc((c + 1) * sizeof(char));

if (array == NULL)
{
return (NULL);
}

for (i = 0; i < c; i++)
{
array[i] = str[i];
}
return (array);

}
