#ifndef COMMON_CALLBACKS_H
#define COMMON_CALLBACKS_H

void free_nop(void*);

int cmp_int(const void*, const void*);
void print_int(const void*);

int cmp_float(const void*, const void*);
void print_float(const void*);

int cmp_double(const void*, const void*);
void print_double(const void*);

int cmp_char_ptr(const void*, const void*);
void print_char_ptr(const void*);

int cmp_long(const void*, const void*);
void print_long(const void*);

int cmp_unsigned_int(const void*, const void*);
void print_unsigned_int(const void*);

#endif
