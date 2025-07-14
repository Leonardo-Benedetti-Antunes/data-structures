#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack Stack;

Stack* stack_create(
    void (*free_func)(void*), 
    void (*print_func)(const void*)
);

void stack_destroy(Stack* stack);

void stack_push(Stack* stack, void* value);

void* stack_pop(Stack* stack);

void* stack_peek(const Stack* stack);

size_t stack_size(const Stack* stack);

int stack_is_empty(const Stack* stack);

void stack_print(const Stack* stack);

#endif