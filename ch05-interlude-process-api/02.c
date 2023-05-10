#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
    int fd;
    pid_t pid;
    
    fd = open("02.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR);
    if (fd < 0) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char *buf = "child\n";
        write(fd, buf, (strlen(buf) + 1) * sizeof(*buf));
    } else {
        char *buf = "parent\n";
        write(fd, buf, (strlen(buf) + 1) * sizeof(*buf));
    }

    return 0;
}
