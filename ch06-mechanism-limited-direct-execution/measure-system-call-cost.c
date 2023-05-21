#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_ITERATION 1000000
#define NSEC_IN_SEC 1e9

int
main() {
    int i, j;
    struct timespec start, end;

    for (j = 0; j < 100; j++) {
        clock_gettime(CLOCK_REALTIME, &start);
        for (i = 0; i < NUM_ITERATION; i++) {
            read(STDIN_FILENO, NULL, 0);
        }
        clock_gettime(CLOCK_REALTIME, &end);

        printf("average: %f\n",
                ((end.tv_sec - start.tv_sec) * NSEC_IN_SEC +
                 (end.tv_nsec - start.tv_nsec)) / NUM_ITERATION);
    }

    return 0;
}
