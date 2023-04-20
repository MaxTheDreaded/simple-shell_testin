#include "main.h"

/**
 * welcome - prints a welcome message
 */
void welcome(void)
{
    printf("Welcome to Our Simple Shell!\n");
    printf("====================================\n");
    printf("Authors: Jesse Otu and Emmanuel Asante\n");
    printf("Type 'exit' to exit.\n");
}

/**
 * readInput - reads input from the user
 * @line: pointer to the line
 * Return: 0 on success, -1 on failure
 */
int readInput(char **line)
{
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    read = getline(line, &len, stdin);
    if (read == -1)
    {
        perror("readInput");
        return (-1);
    }
    return (0);
}

/**
 * _pwd - prints the current working directory
 * Return: 0 on success, -1 on failure
 */
int _pwd(void)
{
    char *cwd;
    char buff[1024];

    cwd = getcwd(buff, 1024);
    if (cwd == NULL)
    {
        perror("_pwd");
        return (-1);
    }
    printf("%s\n", cwd);
    return (0);
}

/**
 * _cd - changes the current working directory
 * @args: arguments
 * Return: 0 on success, -1 on failure
 */
int _cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument to \"cd\"\
        \"cd [directory]\"\"\"n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("_cd");
        }
    }
    return (1);
}

/**
 * exit_shell - exits the shell
 * @args: arguments
 * Return: 0 on success, -1 on failure
 */
int exit_shell(char **args)
{
    if (args[1] == NULL)
    {
        printf("Exiting shell...\n");
        exit(0);
    }
    else
    {
        printf("Exiting shell...\n");
        exit(atoi(args[1]));
    }
    return (0);
}

/**
 * main - main function
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
    char *line = NULL;
    char **args;
    int status = 1;
    int i = 0;
    char *builtin_str[] = {
        "cd",
        "exit",
        "pwd"
    };
    int (*builtin_func[]) () = {
        &_cd,
        &exit_shell,
        &_pwd
    };
    int num_builtins = sizeof(builtin_str) / sizeof(char *);

    welcome();
    while (status)
    {
        if (readInput(&line) == -1)
            return (-1);
        args = strtok(line, " \t\r\n\a");
        if (args[0] == NULL)
            continue;
        for (i = 0; i < num_builtins; i++)
        {
            if (strcmp(args[0], builtin_str[i]) == 0)
            {
                status = (*builtin_func[i])(args);
                break;
            }
        }
        if (i == num_builtins)
        {
            if (fork() == 0)
            {
                if (execve(args[0], args, NULL) == -1)
                {
                    perror("execve");
                    exit_shell(0);
                }
            }
            else
            {
                wait(NULL);
            }
        }
    }
    return (0);
}
