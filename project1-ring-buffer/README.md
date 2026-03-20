# Ring Buffer Library

A lightweight, efficient circular FIFO buffer implementation in C,
designed for embedded systems use cases such as UART drivers,
sensor data pipelines, and RTOS task communication.

## Features

- Fixed-size circular buffer with head/tail pointer design
- Overflow-safe: write returns false when buffer is full
- Underflow-safe: read returns false when buffer is empty
- Wraparound handled correctly via modulo arithmetic

## Project Structure
```
project1-ring-buffer/
├── src/
│   ├── ring_buffer.h   # API definitions
│   └── ring_buffer.c   # Implementation
├── examples/
│   └── producer_consumer.c # Demo program
└── Makefile
```

## Build and Run
```bash
make        # builds the example
./example   # run producer/consumer demo
make clean  # remove built binary
```

## Real-World Relevance

Ring buffers are fundamental in embedded systems — used in UART
receive buffers, audio streaming pipelines, FreeRTOS queues, and
any producer/consumer data flow between ISRs and main code.
