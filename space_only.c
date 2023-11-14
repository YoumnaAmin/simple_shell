#include "main.h"
/**
 *spaces_only - main
 *@s: string
 *Return: 1
*/
int spaces_only(char *s)
{
int i;

for (i = 0; s[i] != '\n'; ++i)
{
if (s[i] != ' ')
return (0);
}
return (1);
}
