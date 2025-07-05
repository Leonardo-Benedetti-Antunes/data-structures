#include "queue.h"

#include <stddef.h>

typedef struct QNode {
    void* value;
    struct QNode* next;
} QNode;

struct Queue{
    QNode* head;
    QNode* tail;
    size_t size;

    void (*free_func)(void*);
    void (*print_func)(const void*);
};

Queue* queue_create(
    void (*free_func)(void*), 
    void (*print_func)(const void*)
){
    Queue* new_queue = malloc(sizeof(Queue));
    if (!new_queue) return NULL;

    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;
    new_queue->free_func = free_func;
    new_queue->print_func = print_func;

    return new_queue;
}

void queue_destroy(Queue* queue) {
    if (!queue) return;
    if (!queue->head) {
        free(queue);
        return;
    }

    QNode* current = queue->head;
    while (current) {
        QNode* next = current->next;

        if (queue->free_func && current->value) {
            queue->free_func(current->value);
        }

        free(current);

        current = next;
    }

    free(queue);
}

void queue_enqueue(Queue* queue, void* value){

    if (!queue) return;

    QNode* new_node = malloc(sizeof(QNode));
    if (!new_node) return;

    new_node->value = value;
    new_node->next = NULL;

    if (!queue->head){
        queue->head = new_node;
    } else {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;
    queue->size++;
}

void* queue_dequeue(Queue* queue) {
    if (!queue || !queue->head) return NULL;

    QNode* old_head = queue->head;
    void* data = old_head->value;

    queue->head = old_head->next;
    if (!queue->head) {
        queue->tail = NULL;
    }

    free(old_head);
    queue->size--;

    return data;
}

void* queue_peek(const Queue* queue){
    if (!queue || !queue->head) return NULL;

    return queue->head->value;
}

size_t queue_size(const Queue* queue){
    if (!queue) return 0;
    return queue->size;
}

int queue_is_empty(const Queue* queue) {
    return (!queue || queue->size == 0);
}

void queue_print(const Queue* queue) {
    if (!queue || !queue->head) {
        return;
    }

    QNode* current = queue->head;

    while (current) {
        if (queue->print_func) {
            queue->print_func(current->value);
        }
        current = current->next;
    }
}
