#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

#define FORK(pid) \
    if(((pid) = fork()) < 0) { \
        perror("fork failed"); \
        exit(EXIT_FAILURE); \
    }

int main(void)
{
    pid_t pid1, pid2;
    int fildes[2] = {0};
    char buf[BUF_SIZE] = {0};

    pipe(fildes); 

    FORK(pid1);
    if (pid1 == 0) {
        dup2(fildes[1], STDOUT_FILENO);
        puts("child1 writes this message to its stdout");
    } else {
        FORK(pid2);
        if (pid2 == 0) {
            dup2(fildes[0], STDIN_FILENO);
            read(STDIN_FILENO, buf, BUF_SIZE);
            printf("child2 read from its stdin as follow:\n %s", buf);
        }
    }

    return 0;
}
