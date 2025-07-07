#ifndef QUEUE_FACTORY_H
#define QUEUE_FACTORY_H

#include "queue.h"

Queue* queue_create_int();
Queue* queue_create_float();
Queue* queue_create_double();
Queue* queue_create_char_ptr();
Queue* queue_create_long();
Queue* queue_create_unsigned_int();

#endif
