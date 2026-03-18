#include "ring_buffer.h"

void rb_init(ring_buffer_t *rb)
{
    rb->head  = 0;
    rb->tail  = 0;
    rb->count = 0;
}

bool rb_is_empty(ring_buffer_t *rb)
{
    return (rb->count == 0);
}

bool rb_is_full(ring_buffer_t *rb)
{
    return (rb->count == RING_BUFFER_SIZE);
}

uint32_t rb_count(ring_buffer_t *rb)
{
    return rb->count;
}

bool rb_write(ring_buffer_t *rb, uint8_t data)
{
    if (rb_is_full(rb)) {
        return false;   /* drop data, buffer full */
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
    rb->count++;
    return true;
}

bool rb_read(ring_buffer_t *rb, uint8_t *data)
{
    if (rb_is_empty(rb)) {
        return false;   /* nothing to read */
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
    rb->count--;
    return true;
}