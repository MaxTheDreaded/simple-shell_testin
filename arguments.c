#include "shell.h"

/**
 * argsParser - parses the arguments
 * @input: input
 * @args: arguments
 * Return: void
 */
void argsParser(char *input, char **args)
{
int i = 0;

while (input[i] != '\0')
{
while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
input[i++] = '\0';
*args++ = &input[i];
while (input[i] != '\0' && input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
i++;
}
*args = NULL;
}
