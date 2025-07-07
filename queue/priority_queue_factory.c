#include "priority_queue_factory.h"
#include "common_callbacks.h"

PriorityQueue* priority_queue_create_int(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_int);
}

PriorityQueue* priority_queue_create_float(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_float);
}

PriorityQueue* priority_queue_create_double(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_double);
}

PriorityQueue* priority_queue_create_char_ptr(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_char_ptr);
}

PriorityQueue* priority_queue_create_long(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_long);
}

PriorityQueue* priority_queue_create_unsigned_int(int min, int max, int ascending) {
    return priority_queue_create(min, max, ascending, free_nop, print_unsigned_int);
}
