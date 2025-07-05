#include "doubly_linked_list_factory.h"
#include "common_callbacks.h"

DoublyLinkedList* d_create_int_list() {
    return d_linked_list_create(free_nop, cmp_int, print_int);
}

DoublyLinkedList* d_create_float_list() {
    return d_linked_list_create(free_nop, cmp_float, print_float);
}

DoublyLinkedList* d_create_double_list() {
    return d_linked_list_create(free_nop, cmp_double, print_double);
}

DoublyLinkedList* d_create_char_ptr_list() {
    return d_linked_list_create(free_nop, cmp_char_ptr, print_char_ptr);
}

DoublyLinkedList* d_create_long_list() {
    return d_linked_list_create(free_nop, cmp_long, print_long);
}

DoublyLinkedList* d_create_unsigned_int_list() {
    return d_linked_list_create(free_nop, cmp_unsigned_int, print_unsigned_int);
}
