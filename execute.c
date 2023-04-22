#include "shell.h"

/**
 * execute - executes the system command
 * @args: arguments
 * Return: 0
 */
void execute(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
perror("Error");
}
else
{
wait(&status);
}
}
