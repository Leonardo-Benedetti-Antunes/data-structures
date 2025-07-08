#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct Queue Queue;

Queue* queue_create(
    void (*free_func)(void*), 
    void (*print_func)(const void*)
);

void queue_destroy(Queue* queue);

void queue_enqueue(Queue* queue, void* value);

void* queue_dequeue(Queue* queue);

void* queue_peek(const Queue* queue);

size_t queue_size(const Queue* queue);

int queue_is_empty(const Queue* queue);

void queue_print(const Queue* queue);

#endif