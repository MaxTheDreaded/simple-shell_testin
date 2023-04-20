#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

/**
 * getppid - gets the process ID of the parent process.
 * Return: Always success;
 */
pid_t getppid(void)
{
    return syscall(SYS_getppid);
}

pid_t getpid(void)
{
    return syscall(SYS_getpid);
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
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();
    printf("Parent process ID: %d\n", ppid);
    printf("Process ID: %d\n", pid);
    for (i = 0; i < ac; i++)
        printf("%s\n", av[i]);
    return 0;
}

