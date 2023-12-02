.SECONDEXPANSION:
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -fsanitize=address
LDFLAGS = -fsanitize=address

days := $(wildcard day-*)

all: $(days) $(days-2)

$(days): $$@/compute-line$(v).o main.o
	$(CC) $(CFLAGS) $^ -o $@.bin

.PHONY: clean
clean:
	$(RM) -rf *.o day-*/*.o *.bin
