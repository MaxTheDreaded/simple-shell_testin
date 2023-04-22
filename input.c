#include "shell.h"

/**
 * readInput - reads input from user
 * @line: pointer to line
 * Return: 0
 */
int readInput(char **line)
{
size_t len = 0;
ssize_t read;

write(STDOUT_FILENO, "$ ", 2);
read = getline(line, &len, stdin);
if (read == -1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS);
}
return (0);
}
