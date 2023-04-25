#include "shell.h"

/**
 * print_env - prints the environment
 * Return: void
 */
void print_env(char **environ)
{
int i = 0;

while (environ[i] != NULL)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}