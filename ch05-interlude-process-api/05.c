#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
    pid_t pid;
    int ret_wait;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("child: pid: %d\n", getpid());
        ret_wait = wait(NULL);
        if (ret_wait < 0) {
            perror("child: wait error");
        }
        printf("child: errno: %d\n", errno);
        printf("child: wait(NULL): %d\n", ret_wait);
    } else {
        printf("parent: pid: %d\n", getpid());
        printf("parent: wait(NULL): %d\n", wait(NULL));
    }

    return 0;
}
