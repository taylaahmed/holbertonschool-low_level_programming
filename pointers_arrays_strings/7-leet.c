#include "main.h"

/**
* leet - replaces letter with corresponding numbers
* @i: char var
*
* Return: value of i
*/

char *leet(char *i)
{
int c = 0;
int b = 0;
int letters[10];
int n[10];
letters[0] = 'a';
letters[1] = 'A';
letters[2] = 'e';
letters[3] = 'E';
letters[4] = 'o';
letters[5] = 'O';
letters[6] = 't';
letters[7] = 'T';
letters[8] = 'l';
letters[9] = 'L';

n[0] = '4';
n[1] = '4';
n[2] = '3';
n[3] = '3';
n[4] = '0';
n[5] = '0';
n[6] = '7';
n[7] = '7';
n[8] = '1';
n[9] = '1';

for (c = 0; i[c] != '\0'; c++)
{
for (b = 0; b <= 9; b++)
{
if (i[c] == letters[b])
{
i[c] = n[b];
}
}
}
return (i);
}
