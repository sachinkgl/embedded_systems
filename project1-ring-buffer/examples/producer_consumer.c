#include <stdio.h>
#include <stdint.h>
#include "../src/ring_buffer.h"

/* Simulates a sensor producing readings */
static void producer(ring_buffer_t *rb)
{
    uint8_t sensor_data[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int count = sizeof(sensor_data) / sizeof(sensor_data[0]);

    printf("[Producer] Sending %d sensor readings...\n", count);
    for (int i = 0; i < count; i++) {
        if (rb_write(rb, sensor_data[i])) {
            printf("[Producer] Wrote: %d\n", sensor_data[i]);
        } else {
            printf("[Producer] Buffer full! Dropped: %d\n", sensor_data[i]);
        }
    }
}

/* Simulates a processor consuming readings */
static void consumer(ring_buffer_t *rb)
{
    uint8_t val;
    printf("\n[Consumer] Reading from buffer...\n");
    while (rb_read(rb, &val)) {
        printf("[Consumer] Read: %d  → processed value: %d\n",
               val, val * 2);
    }
    printf("[Consumer] Buffer empty, done.\n");
}

int main(void)
{
    ring_buffer_t rb;
    rb_init(&rb);

    printf("=== Producer / Consumer Demo ===\n\n");
    producer(&rb);
    printf("\nBuffer now holds %u item(s).\n", rb_count(&rb));
    consumer(&rb);
    printf("\n================================\n");
    return 0;
}