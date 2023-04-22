# C - Simple Shell

## Allowed functions
- `access`
- `chdir`
- `close`
- `closedir`
- `execve`
- `exit`
- `_exit`
- `fflush`
- `fork`
- `free`
- `getcwd`
- `getline`
- `getpid`
- `isatty`
- `kill`
- `malloc`
- `open`
- `opendir`
- `perror`
- `read`
- `readdir`
- `signal`
- `stat`
- `lstat`
- `fstat`
- `strtok`
- `wait`
- `waitpid`
- `wait3`
- `wait4`
- `write`

## Compilation
- Your shell will be compiled this way:

```bash```

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Restrictions

- You are not allowed to use the `printf` function of the standard library. You may use the `write` function.
- Not more than 5 functions per file.