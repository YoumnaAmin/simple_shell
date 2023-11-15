#include "main.h"
/**
 * prompt_display - main
 * Return: always 0
 */

int prompt_display(void)
{
ssize_t r = 0;
char *line = NULL;
size_t len = 0;
char *comment;
/*char *status_str;
int status;*/
char *prompt = "($) ";

if (isatty(0))
{
printf("%s", prompt);
}
r = getline(&line, &len, stdin);
if (spaces_only(line) == 1)
{
free(line);
exit(0);
}
if (r == -1)
{
free(line);
exit(0);
}
comment = _strchr(line, '#');
if (comment != NULL)
{
if (comment == line || *(comment - 1) == ' ')
	*comment = '\0';
}
if (strcmp(line, "exit\n") == 0)
{
	free(line);
    exit(0);
}
/*if (strncmp(line, "exit", 5) == 0)
{
status_str = line + 5;
status = atoi(status_str);

/**
 * if (*status_str == '\0' || !is_valid_integer(status_str))
{
fprintf(stderr, "Illegal number: %s\n", status_str);
free(line);
return (2);
}
*/
free(line);
exit(status);
}*/
split_command(r, &line);
free(line);
return (0);
}
