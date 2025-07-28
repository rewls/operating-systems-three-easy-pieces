CFLAGS := -Wall -Wextra -Werror -g

sources := compare-and-swap.c
programs := $(sources:.c=)

phony += all
all: $(programs)

phony += clean
clean:
	$(RM) $(programs)

.PHONY: $(phony)
