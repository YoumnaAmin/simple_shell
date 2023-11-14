#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int prompt_display(void);
void split_command(ssize_t r, char **ine);
void execute(char **argv);
char *get_path(char *comd);
int spaces_only(char *s);
void print_env(void);
/*int customGetline(char **line, size_t *bufferSize, FILE *stream);*/
char *_strchr(const char *str, int character);
char *_strtok(char *str, const char *delim);
void _cd(char **line);

#endif