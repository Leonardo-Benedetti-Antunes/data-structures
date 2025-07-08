#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

typedef struct PQNode {
    void* data;
    int priority;
    struct PQNode* next;
} PQNode;

struct PriorityQueue {
    PQNode* head;
    size_t size;
    int min_priority;
    int max_priority;
    int ascending;
    void (*free_func)(void*);
    void (*print_func)(const void*);
};

PriorityQueue* priority_queue_create(
    int min_value,
    int max_value,
    int ascending    ,
    void (*free_func)(void*),
    void (*print_func)(const void*)
) {
    if (min_value > max_value || (ascending     != 0 && ascending     != 1)) return NULL;

    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    if (!pq) return NULL;

    pq->head = NULL;
    pq->size = 0;
    pq->min_priority = min_value;
    pq->max_priority = max_value;
    pq->ascending = ascending    ;
    pq->free_func = free_func;
    pq->print_func = print_func;

    return pq;
}

void priority_queue_destroy(PriorityQueue* pq) {
    if (!pq) return;
    PQNode* current = pq->head;
    while (current) {
        PQNode* next = current->next;
        if (pq->free_func && current->data)
            pq->free_func(current->data);
        free(current);
        current = next;
    }
    free(pq);
}

void priority_queue_enqueue(PriorityQueue* pq, void* value, int priority) {
    if (!pq || priority < pq->min_priority || priority > pq->max_priority) return;

    PQNode* new_node = malloc(sizeof(PQNode));
    if (!new_node) return;
    new_node->data = value;
    new_node->priority = priority;
    new_node->next = NULL;

    if (!pq->head ||
        (pq->ascending && priority < pq->head->priority) ||
        (!pq->ascending && priority > pq->head->priority)) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        PQNode* current = pq->head;
        while (current->next &&
              ((pq->ascending && current->next->priority <= priority) ||
               (!pq->ascending && current->next->priority >= priority))) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    pq->size++;
}

void* priority_queue_dequeue(PriorityQueue* pq) {
    if (!pq || !pq->head) return NULL;

    PQNode* temp = pq->head;
    void* data = temp->data;
    pq->head = temp->next;
    free(temp);
    pq->size--;
    return data;
}

void* priority_queue_peek(const PriorityQueue* pq) {
    if (!pq || !pq->head) return NULL;
    return pq->head->data;
}

size_t priority_queue_size(const PriorityQueue* pq) {
    return pq ? pq->size : 0;
}

int priority_queue_is_empty(const PriorityQueue* pq) {
    return (!pq || pq->size == 0);
}

void priority_queue_print(const PriorityQueue* pq) {
    if (!pq || !pq->head) return;

    PQNode* current = pq->head;
    while (current) {
        if (pq->print_func)
            pq->print_func(current->data);
        printf("(priority: %d)", current->priority);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}