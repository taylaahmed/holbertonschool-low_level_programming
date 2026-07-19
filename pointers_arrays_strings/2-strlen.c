#include "main.h"
#include <stdio.h>

/**
* _strlen - function
* @s: variable
*
* Return: value of l
*/

int _strlen(char *s)
{
int l = 0;

while (s[l] != '\0')
{
l++;
}
return (l);
}
