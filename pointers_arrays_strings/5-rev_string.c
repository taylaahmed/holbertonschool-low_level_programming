#include "main.h"

/*
* rev_string - check code
* @*s: var
*/

void rev_string(char *s)
{
int l = 0;
int i;
char c;

while (s[l] != '\0')
{
l++;
}

for (i = 0; i < l/2; i++)
{
c = s[i];
s[i] = s[l - 1 - i];
s[l - 1 - i] = c;
}

}
