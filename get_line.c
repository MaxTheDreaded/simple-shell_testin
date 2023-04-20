#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

/**
 * _getline - reads an entire line from a stream
 * @lineptr: address of a buffer to store the line
 * @n: address of a size_t to store the size of the buffer
 * @stream: stream to read from
 * Return: number of characters read, -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t i = 0;
    char *buf;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return -1;
    buf = *lineptr;
    if (buf == NULL || *n == 0)
    {
        buf = malloc(128);
        if (buf == NULL)
            return -1;
        *n = 128;
    }
    while ((c = fgetc(stream)) != EOF)
    {
        if (i + 1 >= *n)
        {
            *n = *n + 128;
            buf = realloc(buf, *n);
            if (buf == NULL)
                return -1;
        }
        buf[i++] = c;
        if (c == '\n')
            break;
    }
    if (i == 0)
        return -1;
    buf[i] = '\0';
    *lineptr = buf;
    return i;
}

/**
 * main - prints "$ " and waits for the user to enter a command
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("$ ");
        read = _getline(&line, &len, stdin);
        if (read == -1)
        {
            free(line);
            return 0;
        }
        printf("%s", line);
    }
    return 0;
}
