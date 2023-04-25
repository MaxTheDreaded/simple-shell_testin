#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, 1 if not
 */
int _strncmp(char *s1, char *s2, int n)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0' && i < n)
{
if (s1[i] != s2[i])
return (1);
i++;
}
if (s1[i] != s2[i] && i < n)
return (1);
return (0);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @dest: pointer to a buffer
 * @src: pointer to a string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
int i = 0;
char *token;
char *env_var;
char *env_value;

while (environ[i] != NULL)
{
env_var = _strdup(environ[i]);
token = strtok(env_var, "=");
if (_strcmp(token, name) == 0)
{
token = strtok(NULL, "=");
env_value = _strdup(token);
free(env_var);
return (env_value);
}
free(env_var);
i++;
}
return (NULL);
}
