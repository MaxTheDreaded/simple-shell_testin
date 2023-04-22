#include "shell.h"

/**
 * executePipe - executes the piped system commands
 * @args: arguments
 * Return: 0
 */
void executePipe(char **args, char **args2)
{
pid_t pid;
int status;
int fd[2];

if (pipe(fd) == -1)
{
perror("pipe");
exit(EXIT_FAILURE);
}
pid = fork();
if (pid == 0)
{
close(fd[0]);
dup2(fd[1], STDOUT_FILENO);
close(fd[1]);
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
close(fd[1]);
dup2(fd[0], STDIN_FILENO);
close(fd[0]);
if (execve(args2[0], args2, NULL) == -1)
{
perror("Error");
}
}
}
