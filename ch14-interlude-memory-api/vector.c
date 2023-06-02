#include <stdio.h>
#include <stdlib.h>

struct vector {
    int *items;
    int n;
};

void add(struct vector *vec, int item);

int
main(void)
{
    struct vector vec = {NULL, 0};
    
    add(&vec, 1);
    add(&vec, 2);

    printf("item 1: %d, item 2: %d\n", vec.items[0], vec.items[1]);

    free(vec.items);

    return 0;
}

void
add(struct vector *vec, int item)
{
    vec->n++;
    vec->items = realloc(vec->items, vec->n * sizeof(int));
    *(vec->items + vec->n - 1) = item;
}
