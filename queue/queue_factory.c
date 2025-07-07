#include "queue_factory.h"
#include "common_callbacks.h"

Queue* queue_create_int() {
    return queue_create(free_nop, print_int);
}

Queue* queue_create_float() {
    return queue_create(free_nop, print_float);
}

Queue* queue_create_double() {
    return queue_create(free_nop, print_double);
}

Queue* queue_create_char_ptr() {
    return queue_create(free_nop, print_char_ptr);
}

Queue* queue_create_long() {
    return queue_create(free_nop, print_long);
}

Queue* queue_create_unsigned_int() {
    return queue_create(free_nop, print_unsigned_int);
}
