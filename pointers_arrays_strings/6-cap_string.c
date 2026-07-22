#include "main.h"

/**
* cap_string - check code
* @a: char car
*
* Return: value of a
*/

char *cap_string(char *c)
{
int i = 0;
int b = 0;

if (c[0] >= 'a' && c[0] <= 'z')
c[0] -= 32;

for (i = 0; c[i] != '\0'; i++)
{

b = i - 1;

if (c[b] == ',' || c[b] == ';' || c[b] == '.' || c[b] == '!')
{
if (c[i] >= 'a' && c[i] <= 'z')
c[i] -= 32;
}

if (c[b] == '?' || c[b] == '"' || c[b] == ')' || c[b] == '{')
{
if (c[i] >= 'a' && c[i] <= 'z')
c[i] -= 32;
}

if (c[b] == '!' || c[b] == '?' || c[b] == '"' || c[b] == '(')
{
if (c[i] >= 'a' && c[i] <= 'z')
c[i] -= 32;
}

if (c[b] == '}' || c[b] == ' ' || c[b] == '\n' || c[b] == '\t')
{
if (c[i] >= 'a' && c[i] <= 'z')
c[i] -= 32;
}
}
return (c);
}
