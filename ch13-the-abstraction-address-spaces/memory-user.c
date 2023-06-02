#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    long long int i, n;
    char *arr;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]) * (1 << 20);

    arr = calloc(n, 1);

    while (1) {
        for (i = 0; i < n; i++) {
            arr[i] = 1;
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}
