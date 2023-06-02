#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *data;

    data = malloc(100 * sizeof(int));

    free(data);

    printf("%d\n", *data);

    return 0;
}
