#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
char buffer[MAX_LINE];
char *args[MAX_ARGS];

welcome();

while (1)
{
/* Displays a simple prompt and waits for input */
show_prompt();
/* Reads the input from the user */
read_input(buffer);
/* Parses the input from the user */
parse_input(buffer, args);
/* Executes the command */
exec_command(args, environ);

}
return (0);
}
