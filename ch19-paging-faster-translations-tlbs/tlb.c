#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SEC_IN_NSEC 1e9

int
main(int argc, char *argv[])
{
    int *a, i, j, jump, n_page, n_trial, page_size;
    struct timespec end, start;

    if (argc < 3) {
        printf("usage: %s <# pages> <# trials>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n_page = atoi(argv[1]);
    n_trial = atoi(argv[2]);

    page_size = getpagesize();
    jump = page_size / sizeof(int);
    a = calloc(n_page, page_size);

    clock_gettime(CLOCK_REALTIME, &start);
    for (j = 0; j < n_trial; j++) {
        for (i = 0; i < n_page * jump; i += jump) {
            a[i] += 1;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("average: %f\n", ((end.tv_sec - start.tv_sec) * SEC_IN_NSEC + (end.tv_nsec - start.tv_nsec)) / (double)(n_page * n_trial));

    free(a);

    return 0;
}
