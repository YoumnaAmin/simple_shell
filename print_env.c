#include "main.h"
/*
 * print_env - main
 * Return: nothing
 */

void print_env(void)
{
extern char **environ;
char **var;

var = environ;
if (*var == NULL)
{
	fprintf(stderr, "Error: Environment is NULL. Cannot print it.\n");
	exit(2);
}
while (*var != NULL)
{
	printf("%s\n", *var);
	var++;
}
}
