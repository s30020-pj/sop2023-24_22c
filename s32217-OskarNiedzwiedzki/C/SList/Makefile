CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c89

EXECUTABLE = slist_test
SOURCES = slist.c slist_test.c
HEADERS = slist.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
