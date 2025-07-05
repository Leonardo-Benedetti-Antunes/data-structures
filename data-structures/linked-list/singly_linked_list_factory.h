#ifndef SINGLY_LINKED_LIST_FACTORY_H
#define SINGLY_LINKED_LIST_FACTORY_H

#include "singly_linked_list.h"

SinglyLinkedList* s_create_int_list();
SinglyLinkedList* s_create_float_list();
SinglyLinkedList* s_create_double_list();
SinglyLinkedList* s_create_char_ptr_list();
SinglyLinkedList* s_create_long_list();
SinglyLinkedList* s_create_unsigned_int_list();

#endif
