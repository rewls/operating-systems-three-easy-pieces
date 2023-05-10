#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("child: x = %d\n", x);
        x = 200;
        puts("child: execute x = 200");
        printf("child: x = %d\n", x);
    } else {
        printf("parent: x = %d\n", x);
        x = 300;
        puts("parent: execute x = 300");
        printf("parent: x = %d\n", x);
    }

    return 0;
}
