#include "main.h"
/**
 * _exit_arg - to exit when arguments passed
 *
 * @line: string
 * Return: Nothing
*/
void _exit_arg(char *line)
{
	int status;
	char *exit_position = strstr(line, "exit");
	char *newline;

	if (exit_position != NULL)
	{
		exit_position += 4;
	while (*exit_position == ' ')
	{
		exit_position++;
	}
	newline = strchr(exit_position, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
	if (*exit_position == '\0' || spaces_only(exit_position))
	{
		free(line);
		exit(0);
	}
	if (sscanf(exit_position, "%d", &status) != 1)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", exit_position);
		free(line);
		exit(2);
	}
	if (status < 0)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", exit_position);
		free(line);
		exit(2);
	}
	if (status > 255)
	{
		status %= 256;
	}
	free(line);
	exit(status);
	}
}







