#include "doubly_linked_list.h"

#include <stddef.h>
#include <stdlib.h>

typedef struct DNode {
    void* data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

struct DoublyLinkedList {
    DNode* head;
    DNode* tail;
    size_t size;

    void (*free_func)(void*);
    int (*cmp_func)(const void*, const void*);
    void (*print_func)(const void*);
};

DoublyLinkedList* d_linked_list_create(
    void (*free_func)(void*), 
    int (*cmp_func)(const void*, const void*), 
    void (*print_func)(const void*)
){
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    list->free_func = free_func;
    list->cmp_func = cmp_func;
    list->print_func = print_func;

    return list;
}

void d_linked_list_destroy(DoublyLinkedList* list){
    if (!list) return;

    DNode* current = list->head;
    while (current){
        DNode* next = current->next;

        if (list->free_func){
            list->free_func(current->data);
        }

        free(current);
        current = next;
    }

    free(list);
}

void d_linked_list_insert_front(DoublyLinkedList* list, void* value){
    if (!list) return;

    DNode* new_node = malloc(sizeof(DNode));
    if (!new_node) return;

    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }

    list->head = new_node;
    list->size++;
}

void d_linked_list_insert_back(DoublyLinkedList* list, void* value){
    if (!list) return;

    DNode* new_node = malloc(sizeof(DNode));
    if (!new_node) return;

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }

    list->tail = new_node;
    list->size++;
}

void d_linked_list_append_front(DoublyLinkedList* list, DoublyLinkedList* new_list){
    if (!list || !new_list || !new_list->head) return;

    new_list->tail->next = list->head;
    if (list->head) {
        list->head->prev = new_list->tail;
    } else {
        list->tail = new_list->tail;
    }
    list->head = new_list->head;

    list->size += new_list->size;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
}

void d_linked_list_append_back(DoublyLinkedList* list, DoublyLinkedList* new_list){
    if (!list || !new_list || !new_list->head) return;

    if (list->tail) {
        list->tail->next = new_list->head;
        new_list->head->prev = list->tail;
    } else {
        list->head = new_list->head;
    }

    list->tail = new_list->tail;
    list->size += new_list->size;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
}

int d_linked_list_remove(DoublyLinkedList* list, void* value){
    if (!list || !list->cmp_func) return 0;

    DNode* current = list->head;
    while (current){
        if (list->cmp_func(current->data, value) == 0){
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            if (list->free_func) {
                list->free_func(current->data);
            }

            free(current);
            list->size--;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

size_t d_linked_list_size(const DoublyLinkedList* list){
    return list ? list->size : 0;
}

void d_linked_list_print(const DoublyLinkedList* list){
    if (!list || !list->print_func) return;

    DNode* current = list->head;
    while (current){
        list->print_func(current->data);
        current = current->next;
    }
}
