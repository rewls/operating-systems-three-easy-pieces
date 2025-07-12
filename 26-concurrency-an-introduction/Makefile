CFLAGS := -Wall -Wextra -Werror -g
CPPFLAGS := -I../include -pthread

sources := t0.c t1.c
programs := $(sources:.c=)
headers := common_thread.h

all: $(programs)

clean:
	$(RM) $(programs)

$(programs): $(headers)
