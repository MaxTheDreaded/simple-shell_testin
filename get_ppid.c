#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>


pid_t getppid(void)
{
    return syscall(SYS_getppid);
}

/**
 * main - prints the parent process ID
 * Return: 0 on success, 1 on failure
*/
int main(void)
{
    pid_t ppid = getppid();
    printf("Parent process ID: %d\n", ppid);
    return 0;
}
