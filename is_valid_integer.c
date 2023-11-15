#include "main.h"
/**
 * is_valid_integer - main
 * @str: string
 * Return: 1
*/
int is_valid_integer(const char *str)
{
	if (!str || !*str)
		return (0);
	if (!isdigit(*str) && (*str != '-'))
		return (0);
	while (*(++str))
	{
		if (!isdigit(*str))
			return (0);
	}
	return (1);
}
