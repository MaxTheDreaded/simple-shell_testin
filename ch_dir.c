#include "shell.h"

/**
 * _cd - changes the current working directory
 * @args: arguments
 * Return: 0
 */
int _cd(char **args)
{
char *home;
char *new;
int i, j;

home = getenv("HOME");
if (home == NULL)
{
perror("getenv() error");
return (1);
}
if (args[1] == NULL)
{
if (chdir(home) != 0)
{
perror("chdir() error");
}
}
else
{
for (i = 0; home[i] != '\0'; i++)
{
if (home[i] == args[1][0])
{
for (j = 0; args[1][j] != '\0'; j++)
{
if (home[i + j] != args[1][j])
break;
}
if (args[1][j] == '\0')
{
new = home + i + j;
if (chdir(new) != 0)
{
perror("chdir() error");
}
break;
}
}
}
}
return (0);
}
