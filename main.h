#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>


extern char **environ;

int prompt_display(void);
void split_command(ssize_t r, char **ine);
void execute(char **argv);
char *get_path(char *comd);
int spaces_only(char *s);
void print_env(void);
char *_strchr(const char *str, int character);
char *_strtok(char *str, const char *delim);
void _cd(char **line);
int is_valid_integer(const char *str);
void _exit_arg(char *line);
int is_valid_integer(const char *str);


#endif
