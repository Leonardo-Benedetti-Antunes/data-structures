#include "stack.h"
#include <stdlib.h>

typedef struct SNode {
    void* value;
    struct SNode* next;
} SNode;

struct Stack {
    SNode* head;
    size_t size;
    void (*free_func)(void*);
    void (*print_func)(const void*);
};

Stack* stack_create(void (*free_func)(void*), void (*print_func)(const void*)) {
    Stack* new_stack = malloc(sizeof(Stack));
    if (!new_stack) return NULL;
    new_stack->head = NULL;
    new_stack->size = 0;
    new_stack->free_func = free_func;
    new_stack->print_func = print_func;
    return new_stack;
}

void stack_destroy(Stack* stack) {
    if (!stack) return;
    SNode* current = stack->head;
    while (current) {
        SNode* next = current->next;
        if (stack->free_func) stack->free_func(current->value);
        free(current);
        current = next;
    }
    free(stack);
}

void stack_push(Stack* stack, void* value) {
    if (!stack) return;
    SNode* new_node = malloc(sizeof(SNode));
    if (!new_node) return;
    new_node->value = value;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
}

void* stack_pop(Stack* stack) {
    if (!stack || !stack->head) return NULL;
    SNode* old_head = stack->head;
    void* data = old_head->value;
    stack->head = old_head->next;
    free(old_head);
    stack->size--;
    return data;
}

void* stack_peek(const Stack* stack) {
    if (!stack || !stack->head) return NULL;
    return stack->head->value;
}

size_t stack_size(const Stack* stack) {
    return stack ? stack->size : 0;
}

int stack_is_empty(const Stack* stack) {
    return (!stack || stack->size == 0);
}

void stack_print(const Stack* stack) {
    if (!stack) return;
    SNode* current = stack->head;
    while (current) {
        if (stack->print_func) stack->print_func(current->value);
        current = current->next;
    }
}
