#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct PriorityQueue PriorityQueue;

PriorityQueue* priority_queue_create(
    int min_value,
    int max_value,
    int ascending,
    void (*free_func)(void*), 
    void (*print_func)(const void*)
);

void priority_queue_destroy(PriorityQueue* priorityQueue);

void priority_queue_enqueue(PriorityQueue* priorityQueue, void* value, int priority);

void* priority_queue_dequeue(PriorityQueue* priorityQueue);

void* priority_queue_peek(const PriorityQueue* priorityQueue);

size_t priority_queue_size(const PriorityQueue* priorityQueue);

int priority_queue_is_empty(const PriorityQueue* priorityQueue);

void priority_queue_print(const PriorityQueue* priorityQueue);

#endif