#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * str_tok - splits a string into tokens
 * @str: string to split
 * @delim: delimiter to split the string with
 * Return: pointer to an array of tokens
 */
char **str_tok(char *str, char *delim)
{
    char **tokens;
    char *token;
    char *str1, *str2, *saveptr1, *saveptr2;
    int i = 0;

    str1 = strdup(str);
    str2 = strdup(str);
    while (strtok_r(str1, delim, &saveptr1) != NULL)
        i++;
    tokens = malloc(sizeof(char *) * (i + 1));
    if (tokens == NULL)
        return NULL;
    i = 0;
    while ((token = strtok_r(str2, delim, &saveptr2)) != NULL)
    {
        tokens[i] = strdup(token);
        i++;
    }
    tokens[i] = NULL;
    free(str1);
    free(str2);
    return tokens;
}

/**
 * main - prints all arguments it receives, without using ac
 * @ac: number of arguments
 * @av: NULL terminated array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av)
{
    int i;
    char **tokens;

    tokens = str_tok(av[1], " ");
    for (i = 0; tokens[i] != NULL; i++)
        printf("%s\n", tokens[i]);
    return 0;
}
