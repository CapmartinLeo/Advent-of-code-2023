.SECONDEXPANSION:
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -fsanitize=address
LDFLAGS = -fsanitize=address

days := $(wildcard day-*)
days-2 := $(days:=-2)

all: $(days) $(days-2)

$(days): $$@/compute-line.o main.o
	$(CC) $(CFLAGS) $^ -o $@.bin

$(days-2): $$@/compute-line-2.o main.o
	$(CC) $(CFLAGS) $^ -o $@.bin

clean:
	$(RM) -rf *.o day-*/*.o *.bin
