#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * wait() - wait for child process to terminate
 * @status: pointer to an integer to store the child's exit status
 * Return: pid of the child process that terminated, or -1 on error
 */
pid_t wait(int *status) { return waitpid(-1, status, 0); }

/**
 * waitpid() - wait for a child process to terminate
 * @pid: pid of the child process to wait for
 * @status: pointer to an integer to store the child's exit status
 * @options: options to modify the behavior of waitpid()
 * Return: pid of the child process that terminated, or -1 on error
 */
pid_t waitpid(pid_t pid, int *status, int options) {
  int ret;

  ret = syscall(__NR_wait4, pid, status, options, NULL);
  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}

int main(void) {
  pid_t child_pid;
  int status;

  child_pid = fork();
  if (child_pid == -1) {
    perror("Error:");
    return (1);
  }
  if (child_pid == 0) {
    printf("Wait for me, wait for me\n");
    sleep(3);
  } else {
    wait(&status);
    printf("Oh, it's all better now\n");
  }
  return (0);
}
