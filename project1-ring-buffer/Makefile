CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude -Isrc

SRC     = src/ring_buffer.c
EXAMPLE = examples/producer_consumer.c


example: $(SRC) $(EXAMPLE)
	$(CC) $(CFLAGS) -o example $(SRC) $(EXAMPLE)


clean:
	rm -f example

.PHONY: all example clean
