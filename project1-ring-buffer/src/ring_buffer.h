#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RING_BUFFER_SIZE 16

typedef struct {
    uint8_t  buffer[RING_BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
    uint32_t count;
} ring_buffer_t;

void    rb_init(ring_buffer_t *rb);
bool    rb_write(ring_buffer_t *rb, uint8_t data);
bool    rb_read(ring_buffer_t *rb, uint8_t *data);
bool    rb_is_empty(ring_buffer_t *rb);
bool    rb_is_full(ring_buffer_t *rb);
uint32_t rb_count(ring_buffer_t *rb);

#endif /* RING_BUFFER_H */