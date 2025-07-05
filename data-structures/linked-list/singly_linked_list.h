#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef struct SinglyLinkedList SinglyLinkedList;

SinglyLinkedList* s_linked_list_create(
    void (*free_func)(void*), 
    int (*cmp_func)(const void*, const void*), 
    void (*print_func)(const void*)
);

void s_linked_list_destroy(SinglyLinkedList* list);

void s_linked_list_insert_front(SinglyLinkedList* list, void* value);

void s_linked_list_insert_back(SinglyLinkedList* list, void* value);

void s_linked_list_append_front(SinglyLinkedList* list, SinglyLinkedList* new_list);

void s_linked_list_append_back(SinglyLinkedList* list, SinglyLinkedList* new_list);

int s_linked_list_remove(SinglyLinkedList* list, void* value);

size_t s_linked_list_size(const SinglyLinkedList* list);

void s_linked_list_print(const SinglyLinkedList* list);

#endif