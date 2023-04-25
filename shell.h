#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* GLOBAL VARIABLES */

extern char **environ;
#define MAX_LINE 80
#define MAX_ARGS 10
#define MAX_PATH 100

/* FUNCTION PROTOTYPES */

/* welcome.c */
void welcome(void);

/* prompt.c */
void show_prompt(void);
void read_input(char *buffer);

/* interpreter.c */
void parse_input(char *buffer, char **args);
void command_AR(char **args, char **env);
void path_run(char **args, char **env);
void exec_command(char **args, char **env);

/* builtin.c */
void print_env(char **environ);
void exit_shell(int status);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
void _cd(char *args);

/* getline.c */
char *_getline(const int fd);

/* other.c */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _atoi(char *s);
int _strlen(char *s);

/* other_1.c */
int _strncmp(char *s1, char *s2, int n);
char *_getenv(char *name);
char *_strtok(char *str, const char *delim);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);

#endif