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

/**
 * exit_shell - exits the shell with the given status
 * @status: exit status
 * Return: void
 */
void exit_shell(int status)
{
exit(status);
}

/**
 * _setenv - sets the value of an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value)
{
int i = 0;
char *env_var;
char *new_env_var;

while (environ[i] != NULL)
{
env_var = _strdup(environ[i]);
if (env_var != NULL && (_strncmp(env_var, name, _strlen(name)) == 0))
{
new_env_var = malloc(_strlen(name) + _strlen(value) + 2);
_strcpy(new_env_var, name);
_strcat(new_env_var, "=");
_strcat(new_env_var, value);
free(environ[i]);
environ[i] = new_env_var;
free(env_var);
return (0);
}
free(env_var);
i++;
}
return (-1);
}

/**
 * _unsetenv - unsets an environment variable
 * @name: name of the environment variable
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *name)
{
int i = 0;
char *env_var;

while (environ[i] != NULL)
{
env_var = _strdup(environ[i]);
if (env_var != NULL && (_strncmp(env_var, name, _strlen(name)) == 0))
{
free(environ[i]);
while (environ[i + 1] != NULL)
{
environ[i] = environ[i + 1];
i++;
}
environ[i] = NULL;
free(env_var);
return (0);
}
free(env_var);
i++;
}
return (-1);
}

/**
 * _cd - changes the current working directory
 * @args: arguments
 * change directory to HOME if no arguments are given
 * change directory to the previous directory
 * if "-" is given as an argument
 * change directory to the path specified in the first argument
 * Return: void
 */
void _cd(char *args)
{
char *home = _getenv("HOME");
char *oldpwd = _getenv("OLDPWD");
char *pwd = _getenv("PWD");
char *newpwd;
char *token;
char *path;

if (args == NULL)
{
if (chdir(home) == -1)
{
perror("hsh");
}
else
{
newpwd = malloc(_strlen(home) + 6);
_strcpy(newpwd, "PWD=");
_strcat(newpwd, home);
_setenv("PWD", home);
_setenv("OLDPWD", pwd);
free(newpwd);
}
}
else if (_strcmp(args, "-") == 0)
{
if (chdir(oldpwd) == -1)
{
perror("hsh");
}
else
{
newpwd = malloc(_strlen(oldpwd) + 6);
_strcpy(newpwd, "PWD=");
_strcat(newpwd, oldpwd);
_setenv("PWD", oldpwd);
_setenv("OLDPWD", pwd);
free(newpwd);
}
}
else
{
token = strtok(args, " ");
while (token != NULL)
{
path = malloc(_strlen(token) + 1);
_strcpy(path, token);
token = strtok(NULL, " ");
}
if (chdir(path) == -1)
{
perror("hsh");
}
else
{
newpwd = malloc(_strlen(path) + 6);
_strcpy(newpwd, "PWD=");
_strcat(newpwd, path);
_setenv("PWD", path);
_setenv("OLDPWD", pwd);
free(newpwd);
}
free(path);
}
free(home);
free(oldpwd);
free(pwd);
}
