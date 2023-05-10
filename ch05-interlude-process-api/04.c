#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define FORK(pid) \
    if(((pid) = fork()) < 0) { \
        perror("fork failed"); \
        exit(EXIT_FAILURE); \
    }

int main(void)
{
    pid_t pid;

    FORK(pid);
    if (pid == 0) {
        execve("/bin/ls", (char *[]){"ls", NULL}, (char *[]){NULL});
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
        printf("execve end\n");
    }

    FORK(pid);
    if (pid == 0) {
        execl("/bin/ls", "ls");
    } else {
        wait(NULL);
        printf("execl end\n");
    }

    FORK(pid);
    if (pid == 0) {
        execle("/bin/ls", "ls");
    } else {
        wait(NULL);
        printf("execle end\n");
    }
    
    FORK(pid);
    if (pid == 0) {
        execlp("ls", "ls");
    } else {
        wait(NULL);
        printf("execlp end\n");
    }

    FORK(pid);
    if (pid == 0) {
        execv("/bin/ls", (char *[]){"ls", NULL});
    } else {
        wait(NULL);
        printf("execv end\n");
    }

    FORK(pid);
    if (pid == 0) {
        execvp("ls", (char *[]){"ls", NULL});
    } else {
        wait(NULL);
        printf("execvp end\n");
    }

    FORK(pid);
    if (pid == 0) {
        execvpe("ls", (char *[]){"ls", NULL}, (char *[]){NULL});
    } else {
        wait(NULL);
        printf("execvpe end\n");
    }

    return 0;
}
