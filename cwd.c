#include "shell.h"

/**
 * _pwd - prints the current working directory
 * @args: arguments
 * Return: 0
 */
int _pwd(void)
{
char *cwd;
char *home;
char *new;
int i, j;

cwd = getcwd(NULL, 0);
home = getenv("HOME");
if (cwd == NULL)
{
perror("getcwd() error");
return (1);
}
if (home == NULL)
{
perror("getenv() error");
return (1);
}
if (strcmp(cwd, home) == 0)
{
write(STDOUT_FILENO, "~", 1);
write(STDOUT_FILENO, "\n", 1);
}
else
{
for (i = 0; cwd[i] != '\0'; i++)
{
if (cwd[i] == home[0])
{
for (j = 0; home[j] != '\0'; j++)
{
if (cwd[i + j] != home[j])
break;
}
if (home[j] == '\0')
{
new = cwd + i + j;
write(STDOUT_FILENO, "~", 1);
write(STDOUT_FILENO, new, strlen(new));
write(STDOUT_FILENO, "\n", 1);
break;
}
}
}
}
free(cwd);
return (0);
}
