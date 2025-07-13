sources := thread_create.c \
	   thread_create_simple_args.c
programs := $(sources:.c=)

include_dir := ../include
includes := $(include_dir)/common_threads.h

CFLAGS := -Wall -Wextra -Werror -g
CPPFLAGS = -I$(include_dir)

phony += all
all: $(programs)

phony += clean
clean:
	$(RM) $(programs)

$(programs): $(headers)

.PHONY: $(phony)
