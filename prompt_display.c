#include "main.h"

/**
 * prompt_display - main
 * Return: 0 if the shell should continue, 1 if it should exit
 */
int prompt_display(void)
{
    ssize_t r = 0;
    char *line = NULL;
    size_t len = 0;
    char *comment;
    char *prompt = "($) ";

    if (isatty(0)) {
        printf("%s", prompt);
    }

    r = getline(&line, &len, stdin);

    if (r == -1) {
        free(line);
        if (isatty(0)) {
            printf("\n");
        }
        return 1;  
    }
	if (spaces_only(line) == 1)
	{
		free(line);
		return 1;
	}

    comment = _strchr(line, '#');
    if (comment != NULL && (comment == line || *(comment - 1) == ' ')) {
        *comment = '\0';
    }

    if (strcmp(line, "exit\n") == 0) {
        free(line);
        return 1; 
    }

    split_command(r, &line);
    free(line);

    return 0; 
}
