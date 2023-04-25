#include "shell.h"

/**
 * show_prompt - displays the prompt
 * Return: void
 */
void show_prompt(void)
{
/* Displays a simple prompt and waits for input */
write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_input - reads the input from the user
 * @buffer: buffer to store the input
 * Return: void
 */
void read_input(char *buffer)
{
/* Reads the input from the user */
int i = 0;
char c;

while (1)
{
read(STDIN_FILENO, &c, 1);
if (c == '\n')
{
buffer[i] = '\0';
break;
}
buffer[i] = c;
i++;
}
}
