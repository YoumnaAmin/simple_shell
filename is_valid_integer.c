#include "main.h"
/**
 * is_valid_integer - main
 * @str: string
 * Return: 1
*/
int is_valid_integer(const char *str)
{
while (*str != '\0')
{
if (!isdigit((unsigned char)*str))
{
return (0);
}
str++;
}
return (1);
}
