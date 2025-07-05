#ifndef DOUBLY_LINKED_LIST_FACTORY_H
#define DOUBLY_LINKED_LIST_FACTORY_H

#include "doubly_linked_list.h"

DoublyLinkedList* d_create_int_list();
DoublyLinkedList* d_create_float_list();
DoublyLinkedList* d_create_double_list();
DoublyLinkedList* d_create_char_ptr_list();
DoublyLinkedList* d_create_long_list();
DoublyLinkedList* d_create_unsigned_int_list();

#endif