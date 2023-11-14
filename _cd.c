#include "main.h"
/**
 * _cd - custom cd
 * @line: takes a line of string as arguments
 * Return: Nothing
*/
void _cd(char **line)
{
	int i;
	char **loc_line,  buf[1024];

	loc_line = line;
	for (i = 0; loc_line[i] != NULL; i++)
	{; }
	i--;
	if (i == 0)
	{
		chdir(getenv("HOME"));
	}
	else if (strcmp(loc_line[1], "-") == 0)
	{
		if (getenv("OLDPWD") == NULL)
		{
			fprintf(stdout, "%s\n", getcwd(buf, 1024));

		}
		chdir(getenv("OLDPWD"));
	}
	else
	{
		if (chdir(loc_line[1]) != 0)
		{
			fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", loc_line[1]);
		}
	}
}
