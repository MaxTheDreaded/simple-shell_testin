#include "shell.h"

/**
 * interpreter - interprets the input
 * @args: arguments
 * Return: void
 */
void interpreter(char **args)
{
pid_t pid;
int status;

if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
else if (strcmp(args[0], "cd") == 0)
{
_cd(args);
}
else if (strcmp(args[0], "pwd") == 0)
{
_pwd();
}
else
{
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execvp() error");
}
exit(0);
}
else if (pid < 0)
{
perror("fork() error");
}
else
{
wait(&status);
}
}
}
