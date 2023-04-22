#include "shell.h"

/**
 * main - main function
 * Return: 0
 */
int main(void)
{
char **input[MAX_LINE];
char *args[MAX_LINE / 2 + 1];
int should_run = 1;

welcome();
while (should_run)
{
write(STDOUT_FILENO, "$ ", 2);
if (fgets(**input, MAX_LINE, stdin) == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}
argsParser(**input, args);
interpreter(args);
}
return (0);
}
