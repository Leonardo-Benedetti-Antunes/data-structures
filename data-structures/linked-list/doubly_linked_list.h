#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* d_linked_list_create(
    void (*free_func)(void*), 
    int (*cmp_func)(const void*, const void*), 
    void (*print_func)(const void*)
);

void d_linked_list_destroy(DoublyLinkedList* list);

void d_linked_list_insert_front(DoublyLinkedList* list, void* value);

void d_linked_list_insert_back(DoublyLinkedList* list, void* value);

void d_linked_list_append_front(DoublyLinkedList* list, DoublyLinkedList* new_list);

void d_linked_list_append_back(DoublyLinkedList* list, DoublyLinkedList* new_list);

int d_linked_list_remove(DoublyLinkedList* list, void* value);

size_t d_linked_list_size(const DoublyLinkedList* list);

void d_linked_list_print(const DoublyLinkedList* list);

#endif