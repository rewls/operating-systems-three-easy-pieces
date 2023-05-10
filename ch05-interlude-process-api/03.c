#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal);

int main(void)
{
    pid_t parent_pid, ret_fork;

    parent_pid = getpid();

    signal(SIGUSR1, signal_handler);

    ret_fork = fork();
    if (ret_fork < 0) {
        perror("fork faild");
    } else if (ret_fork == 0) {
        puts("hello");
        kill(parent_pid, SIGUSR1);
    } else {
        pause();
    }

    return 0;
}

void signal_handler(int signal)
{
    if (signal == SIGUSR1) {
        puts("goodbye");
        exit(EXIT_SUCCESS);
    }
}
