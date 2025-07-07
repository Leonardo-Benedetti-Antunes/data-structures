#ifndef PRIORITY_QUEUE_FACTORY_H
#define PRIORITY_QUEUE_FACTORY_H

#include "priority_queue.h"

PriorityQueue* priority_queue_create_int(int min, int max, int ascending);
PriorityQueue* priority_queue_create_float(int min, int max, int ascending);
PriorityQueue* priority_queue_create_double(int min, int max, int ascending);
PriorityQueue* priority_queue_create_char_ptr(int min, int max, int ascending);
PriorityQueue* priority_queue_create_long(int min, int max, int ascending);
PriorityQueue* priority_queue_create_unsigned_int(int min, int max, int ascending);

#endif
