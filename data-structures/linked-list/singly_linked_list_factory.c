#include "singly_linked_list_factory.h"
#include "common_callbacks.h"

SinglyLinkedList* s_create_int_list() {
    return s_linked_list_create(free_nop, cmp_int, print_int);
}

SinglyLinkedList* s_create_float_list() {
    return s_linked_list_create(free_nop, cmp_float, print_float);
}

SinglyLinkedList* s_create_double_list() {
    return s_linked_list_create(free_nop, cmp_double, print_double);
}

SinglyLinkedList* s_create_char_ptr_list() {
    return s_linked_list_create(free_nop, cmp_char_ptr, print_char_ptr);
}

SinglyLinkedList* s_create_long_list() {
    return s_linked_list_create(free_nop, cmp_long, print_long);
}

SinglyLinkedList* s_create_unsigned_int_list() {
    return s_linked_list_create(free_nop, cmp_unsigned_int, print_unsigned_int);
}