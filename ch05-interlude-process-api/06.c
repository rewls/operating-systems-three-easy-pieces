#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
    pid_t ret_fork, child_pid;
    int ret_wait;

    ret_fork = fork();
    if (ret_fork < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (ret_fork == 0) {
        child_pid = getpid();
        printf("child: pid: %d\n", child_pid);
        ret_wait = waitpid(child_pid, NULL, 0);
        if (ret_wait < 0) {
            perror("child: wait error");
        }
        printf("child: errno: %d\n", errno);
        printf("child: wait(NULL): %d\n", ret_wait);
    } else {
        printf("parent: pid: %d\n", getpid());
        printf("parent: wait(NULL): %d\n", waitpid(ret_fork, NULL, 0));
    }

    return 0;
}
