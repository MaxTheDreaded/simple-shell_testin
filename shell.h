#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */

void welcome(void);
int readInput(char **line);
int _pwd(void);
int _cd(char **args);
void argsParser(char *line, char **args);
void argsExec(char **args);
void interpreter(char **args);

#endif
