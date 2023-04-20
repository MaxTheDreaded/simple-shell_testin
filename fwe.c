#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

#define __NR_execve 59

/**
 * main - executes the command ls -l /tmp/ in 5 different child processes
 * each child process should be created by the same parent process.
 * wait for each child process to terminate before creating a new one.
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int i;
    int status;
    pid_t pid;
    char *argv[] = {"/bin/ls", "-l", "./", NULL};

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (pid == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error:");
            }
        }
        else
        {
            wait(&status);
        }
    }
    return (0);
}

