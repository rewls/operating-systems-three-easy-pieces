#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int
main(void)
{
	int *p = malloc(sizeof(int));					// a1
	assert(p != NULL);
	printf("(%d) address pointed to by p: %p\n", getpid(), p);	// a2
	*p = 0;								// a3
	while (1) {
		Spin(1);
		*p = *p + 1;
		printf("(%d) value of p: %d\n", getpid(), *p);		// a4
	}
	return 0;
}
