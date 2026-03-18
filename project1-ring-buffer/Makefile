CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude -Isrc

SRC     = src/ring_buffer.c
TEST    = tests/test_ring_buffer.c
EXAMPLE = examples/producer_consumer.c

all: example test

example: $(SRC) $(EXAMPLE)
	$(CC) $(CFLAGS) -o example $(SRC) $(EXAMPLE)

test: $(SRC) $(TEST)
	$(CC) $(CFLAGS) -o test_runner $(SRC) $(TEST)

clean:
	rm -f example test_runner

.PHONY: all example test clean