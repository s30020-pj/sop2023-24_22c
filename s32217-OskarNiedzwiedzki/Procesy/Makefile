CC = gcc
CFLAGS = -Wall --ansi --pedantic

# Define the output directory
OUT_DIR = ./compile

# Find all .c files in the current directory
SRC = $(wildcard *.c)

# Define the object files, placing them in the output directory
OBJ = $(patsubst %.c,$(OUT_DIR)/%,$(SRC))

# Default target
all: $(OBJ)

# Rule to compile .c files
$(OUT_DIR)/%: %.c
        @mkdir -p $(OUT_DIR)
        $(CC) $(CFLAGS) -o $@ $<
        @chmod +rx $@

# Clean target to remove compiled files
clean:
        rm -rf $(OUT_DIR)

# Phony targets
.PHONY: all clean