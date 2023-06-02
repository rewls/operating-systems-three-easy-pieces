#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *data;

    data = malloc(100 * sizeof(int));

    data[100] = 0;

    free(data);

    return 0;
}
