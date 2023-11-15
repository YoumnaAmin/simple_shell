#include "main.h"
/**
 * split_command - main
 * @r: string
 * @line: copy the line of string
 * Return : nothing
*/
void split_command(ssize_t r, char **line)
{
int i;
int w_num = 0;
char *word;
char **argv;
char *line_cp;
const char *delim = " \t\n";

line_cp = malloc(sizeof(char) * (r + 1));
if (line_cp == NULL)
{
perror("Memory allocation error");
exit(0);
}
strcpy(line_cp, *line);

word = _strtok(*line, delim);
while (word != NULL)
{
w_num++;
word = _strtok(NULL, delim);
																		}
argv = malloc(sizeof(char *) * (w_num + 1));
if (argv == NULL)
{
perror("Memory allocation error");
exit(0);
}
word = _strtok(line_cp, delim);
for (i = 0; word != NULL; i++)
{
argv[i] = malloc(sizeof(char) * (strlen(word) + 1));
strcpy(argv[i], word);
word = _strtok(NULL, delim);
}
argv[i] = NULL;
execute(argv);
for (i = 0; i < w_num; i++)
{
	free(argv[i]);
}
free(line_cp);
free(argv);
}
