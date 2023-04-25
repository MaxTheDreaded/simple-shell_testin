#include "shell.h"

/**
 * parse_input - parses the input from the user
 * @buffer: buffer to store the input
 * @args: array of arguments
 * Return: void
 */
void parse_input(char *buffer, char **args)
{
int i = 0;
char *token;

token = strtok(buffer, " \n");
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " \n");
i++;
}
args[i] = NULL;
}

/**
 * command_AR - check if the command is an absolute or relative path
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void command_AR(char **args, char **env)
{
pid_t pid;

/* Fork a child process */
pid = fork();
if (pid == 0)
{
/* Child process */
if (execve(args[0], args, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
/* Error forking */
perror("Error");
}
}

/**
 * path_run - executes the command with the arguments
 * checks in PATH
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void path_run(char **args, char **env)
{
int i = 0;
char *path;
char *token;
char *path_array[100];
pid_t pid;
char *command;
struct stat st;

/* Get the PATH variable */
path = _getenv("PATH");
/* Tokenize the PATH variable */
token = strtok(path, ":");
/* Store the tokens in the path_array */
while (token != NULL)
{
path_array[i] = token;
token = strtok(NULL, ":");
i++;
}
path_array[i] = NULL;
/* Concatenate the command with the path */
for (i = 0; path_array[i] != NULL; i++)
{
command = _strcat(path_array[i], "/");
command = _strcat(command, args[0]);
/* Check if the file exists */
if (stat(command, &st) == 0)
{
/* Fork a child process only if the file exists */
pid = fork();
if (pid == 0)
{
/* Child process */
if (execve(command, args, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
/* Error forking */
perror("Error");
}
else
{
/* Parent process */
waitpid(pid, NULL, 0);
}
break;
}
if (stat(command, &st) != 0)
{
if (path_array[i + 1] == NULL)
{
write(STDERR_FILENO, "Command not found", 17);
write(STDERR_FILENO, "\n", 1);
return;
}
}
}
}

/**
 * exec_command - executes the command with the arguments
 * checks in PATH
 * @args: array of arguments
 * Return: void
 */
void exec_command(char **args, char **env)
{
/* Check if the command is empty */
if (args[0] == NULL)
return;
/* Check if the command is exit */
if (_strcmp(args[0], "exit") == 0)
exit(0);
/* Check if the command is exit with a status */
if (_strcmp(args[0], "exit") == 0 && args[1] != NULL)
exit(_atoi(args[1]));
/* Check if the command is env */
if (_strcmp(args[0], "env") == 0)
{
print_env(env);
return;
}
/* Check if the command is setenv */
if (_strcmp(args[0], "setenv") == 0)
{
_setenv(args[1], args[2]);
return;
}
/* Check if the command is unsetenv */
if (_strcmp(args[0], "unsetenv") == 0)
{
_unsetenv(args[1]);
return;
}
/* Check if the command is cd */
if (_strcmp(args[0], "cd") == 0)
{
_cd(args[1]);
return;
}

/* Check if the command is an absolute or relative path */
if (args[0][0] == '/' || args[0][0] == '.')
command_AR(args, env);
else
path_run(args, env);
}