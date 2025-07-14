#include "binary_tree_factory.h"
#include "common_callbacks.h"

BinaryTree* binary_tree_create_int() {
    return binary_tree_create(free_nop, print_int);
}

BinaryTree* binary_tree_create_float() {
    return binary_tree_create(free_nop, print_float);
}

BinaryTree* binary_tree_create_double() {
    return binary_tree_create(free_nop, print_double);
}

BinaryTree* binary_tree_create_char_ptr() {
    return binary_tree_create(free_nop, print_char_ptr);
}

BinaryTree* binary_tree_create_long() {
    return binary_tree_create(free_nop, print_long);
}

BinaryTree* binary_tree_create_unsigned_int() {
    return binary_tree_create(free_nop, print_unsigned_int);
}