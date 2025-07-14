#ifndef STACK_FACTORY_H
#define STACK_FACTORY_H

#include "stack.h"

Stack* stack_create_int();
Stack* stack_create_float();
Stack* stack_create_double();
Stack* stack_create_char_ptr();
Stack* stack_create_long();
Stack* stack_create_unsigned_int();

#endif
