#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */

int execve(const char *filename, char *const argv[], char *const envp[]);
int fork(void);
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
pid_t getppid(void);
pid_t getpid(void);
char **str_tok(char *str, char *delim);

#endif
