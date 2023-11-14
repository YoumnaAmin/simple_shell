#include "main.h"
/**
 * _strchr - custom strchr
 * @str: the line of string'
 * @character: the char to compare
 * Return: pointer to char
*/
char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
/**
 * _strtok - a custom strtok
 * @str: the command line
 * @delim: the delim
 * Return: pointer to characters
*/
char *_strtok(char *str, const char *delim)
{
	static char *ptr;
	int i;

	if (str != NULL)
		ptr = str;


	while (*ptr != '\0' && _strchr(delim, *ptr) != NULL)
		ptr++;
	if (*ptr == '\0')
		return (NULL);
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (_strchr(delim, ptr[i]) != NULL)
		{
			ptr[i] = '\0';
			ptr = &ptr[i + 1];
			return (ptr - i - 1);
		}
	}
	ptr = &ptr[i];
	return (ptr - i);
}
