CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c89

EXECUTABLE = dlist_test
SOURCES = dlist.c dlist_test.c
HEADERS = dlist.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
