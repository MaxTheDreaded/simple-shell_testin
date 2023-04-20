#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

#define __NR_execve 59

/**
 * execve - executes a program
 * @filename: name of the program to execute
 * @argv: array of arguments to pass to the program
 * @envp: array of environment variables to pass to the program
 * Return: -1 on failure
 */
int execve(const char *filename, char *const argv[], char *const envp[])
{
    int ret;

    ret = syscall(__NR_execve, filename, argv, envp);
    if (ret < 0)
    {
        errno = -ret;
        return (-1);
    }
    return (ret);
}

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
