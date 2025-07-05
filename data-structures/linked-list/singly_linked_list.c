#include "singly_linked_list.h"

#include <stddef.h>
#include <stdlib.h>

typedef struct SNode {
    void* data;
    struct SNode* next;
} SNode;

struct SinglyLinkedList {
    SNode* head;
    size_t size;

    void (*free_func)(void*);
    int (*cmp_func)(const void*, const void*);
    void (*print_func)(const void*);
};

SinglyLinkedList* s_linked_list_create(
    void (*free_func)(void*), 
    int (*cmp_func)(const void*, const void*), 
    void (*print_func)(const void*)
){
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->size = 0;
    
    list->free_func = free_func;
    list->cmp_func = cmp_func;
    list->print_func = print_func;

    return list;
}

void s_linked_list_destroy(SinglyLinkedList* list){
    if (!list) return;

    SNode* current = list->head;

    while (current){
        SNode* next = current->next;

        if (list->free_func){
            list->free_func(current->data);
        }

        free(current);

        current = next;
    }

    free(list);
}

void s_linked_list_insert_front(SinglyLinkedList* list, void* value){
    if (!list) return;

    SNode* old_head = list->head;

    SNode* new_head = malloc(sizeof(SNode));
    if (!new_head) return;

    new_head->next = old_head;
    new_head->data = value;
    list->head = new_head;
    list->size++;
}

void s_linked_list_insert_back(SinglyLinkedList* list, void* value) {
    if (!list) return;

    SNode* new_node = malloc(sizeof(SNode));
    if (!new_node) return;

    new_node->data = value;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
    } else {
        SNode* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
}

void s_linked_list_append_front(SinglyLinkedList* list, SinglyLinkedList* new_list){
    if (!list || !new_list || !new_list->head) return;

    SNode* new_list_tail = new_list->head;

    while (new_list_tail->next){
        new_list_tail = new_list_tail->next;
    }

    new_list_tail->next = list->head;

    list->head = new_list->head;

    list->size += new_list->size;

    new_list->head = NULL;
    new_list->size = 0;
}

void s_linked_list_append_back(SinglyLinkedList* list, SinglyLinkedList* new_list){
    if (!list || !new_list || !new_list->head) return;

    if (!list->head) {
        list->head = new_list->head;
    } else {
        SNode* list_tail = list->head;
        while (list_tail->next) {
            list_tail = list_tail->next;
        }
        list_tail->next = new_list->head;
    }

    list->size += new_list->size;

    new_list->head = NULL;
    new_list->size = 0;
}

int s_linked_list_remove(SinglyLinkedList* list, void* value){
    if (!list || !list->head || !list->cmp_func) return 0;

    SNode* current = list->head;
    SNode* prev = NULL;

    while (current){
         if (list->cmp_func(current->data, value) == 0){
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (list->free_func) {
                list->free_func(current->data);
            }

            free(current);
            list->size--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

size_t s_linked_list_size(const SinglyLinkedList* list){
    return list ? list->size : 0;
}

void s_linked_list_print(const SinglyLinkedList* list){
    if (!list || !list->print_func) return;

    SNode* current = list->head;

    while (current){
        list->print_func(current->data);
        current = current->next;
    }
}
