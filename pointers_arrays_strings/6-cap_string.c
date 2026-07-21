#include "main.h"

/**
* cap_string - check code
* @a: char car
*
* Return: value of a
*/

char *cap_string(char *c)
{
int count;

for (count = 0; c[count] != '\0'; count++)
{
if (c[count - 1] == ',' || c[count - 1] == ';' || c[count - 1] == '.' || c[count - 1] == '!' || c[count - 1] == '?' || c[count - 1] == '"' || c[count - 1] == '(' || c[count - 1] == ')' || c[count - 1] == '{' || c[count - 1] == '}' || c[count - 1] == ' ' || c[count - 1] == '\n' || c[count - 1] == '\t')
{
if (c[count] >= 'a' && c[count] <= 'z')
{
c[count] -= 32;
}
}
}
return (c);
}
