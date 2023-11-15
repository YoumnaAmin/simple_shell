#include "main.h"
/**
 * get_path - main
 * @comd: user input commnd
 * Return: comd
 */

char *get_path(char *comd)
{
    char *path, *path_cp, *path_div, *path_file;
    int comd_len, path_div_len;
    struct stat buffer;

    path = getenv("PATH");
    if (path)
    {
        path_cp = strdup(path);
        comd_len = strlen(comd);
        path_div = _strtok(path_cp, ":");
        while (path_div != NULL)
        {
            path_div_len = strlen(path_div);
            path_file = malloc(comd_len + path_div_len + 2);
            if (path_file == NULL)
            {
                perror("Memory allocation error");
                free(path_cp);
				free(path_file);  
                exit(EXIT_FAILURE);
            }
            strcpy(path_file, path_div);
            strcat(path_file, "/");
            strcat(path_file, comd);
            strcat(path_file, "\0");
            if (stat(path_file, &buffer) == 0)
            {
                free(path_cp);  
                return (path_file);
            }
            else
            {
				free(path_file);
                path_div = _strtok(NULL, ":");
            }
        }
        free(path_cp);
        if (stat(comd, &buffer) == 0)
            return (comd);
        return (NULL);
    }
    return (NULL);
}
