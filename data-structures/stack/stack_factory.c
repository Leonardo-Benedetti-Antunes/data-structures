#include "stack_factory.h"
#include "common_callbacks.h"

Stack* stack_create_int() {
    return stack_create(free_nop, print_int);
}

Stack* stack_create_float() {
    return stack_create(free_nop, print_float);
}

Stack* stack_create_double() {
    return stack_create(free_nop, print_double);
}

Stack* stack_create_char_ptr() {
    return stack_create(free_nop, print_char_ptr);
}

Stack* stack_create_long() {
    return stack_create(free_nop, print_long);
}

Stack* stack_create_unsigned_int() {
    return stack_create(free_nop, print_unsigned_int);
}
