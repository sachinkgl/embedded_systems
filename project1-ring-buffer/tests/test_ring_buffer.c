#include <stdio.h>
#include <assert.h>
#include "../src/ring_buffer.h"

static int tests_run    = 0;
static int tests_passed = 0;

#define TEST(name) void test_##name(void)
#define RUN(name)  do { tests_run++; test_##name(); tests_passed++; \
                   printf("[PASS] " #name "\n"); } while(0)

TEST(init)
{
    ring_buffer_t rb;
    rb_init(&rb);
    assert(rb_is_empty(&rb) == true);
    assert(rb_is_full(&rb)  == false);
    assert(rb_count(&rb)    == 0);
}

TEST(write_and_read)
{
    ring_buffer_t rb;
    uint8_t val;
    rb_init(&rb);

    assert(rb_write(&rb, 42) == true);
    assert(rb_count(&rb)     == 1);
    assert(rb_read(&rb, &val) == true);
    assert(val == 42);
    assert(rb_is_empty(&rb)  == true);
}

TEST(full_buffer)
{
    ring_buffer_t rb;
    rb_init(&rb);

    for (int i = 0; i < RING_BUFFER_SIZE; i++) {
        assert(rb_write(&rb, (uint8_t)i) == true);
    }
    assert(rb_is_full(&rb)   == true);
    assert(rb_write(&rb, 99) == false);  /* must reject when full */
}

TEST(wraparound)
{
    ring_buffer_t rb;
    uint8_t val;
    rb_init(&rb);

    /* fill and drain halfway to force wraparound */
    for (int i = 0; i < 8; i++) rb_write(&rb, (uint8_t)i);
    for (int i = 0; i < 8; i++) rb_read(&rb, &val);

    /* now write again — head wraps around the buffer end */
    for (int i = 0; i < 8; i++) rb_write(&rb, (uint8_t)(i + 10));
    for (int i = 0; i < 8; i++) {
        rb_read(&rb, &val);
        assert(val == (uint8_t)(i + 10));
    }
    assert(rb_is_empty(&rb) == true);
}

int main(void)
{
    printf("=== Ring Buffer Tests ===\n");
    RUN(init);
    RUN(write_and_read);
    RUN(full_buffer);
    RUN(wraparound);
    printf("=========================\n");
    printf("Results: %d/%d passed\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}