CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c89

SOURCES = fibonacci.c io_1.c io_2.c ptr_1.c ptr_2.c z1_1.c z1_2.c z1_3.c
EXECUTABLES = $(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)