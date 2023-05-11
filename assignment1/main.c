#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

#define SYSCALL_NUMBER 451 

int main(void)
{
    long int res = syscall(SYSCALL_NUMBER);
    printf("sys_dajincall returned %ld\n", res);
    return 0;
}
