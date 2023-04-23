#include <stdio.h>
#include <unistd.h>

int main()
{
write(STDOUT_FILENO,"HELLO\n",7);
}
