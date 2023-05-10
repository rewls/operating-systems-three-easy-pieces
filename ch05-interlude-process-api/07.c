#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    char buf[1024];

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        close(STDOUT_FILENO);
        sprintf(buf, "printf() return value: %d\n", printf("child\n"));
        write(STDERR_FILENO, buf, strlen(buf) + 1);
    }

    return 0;
}
