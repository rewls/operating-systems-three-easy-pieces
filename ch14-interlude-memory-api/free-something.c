#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *data;

    data = malloc(10 * sizeof(int));

    free(data + 5);

    return 0;
}
