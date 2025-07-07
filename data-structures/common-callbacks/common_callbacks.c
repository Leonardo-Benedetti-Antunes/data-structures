#include "common_callbacks.h"
#include <stdio.h>
#include <string.h>

void free_nop(void* data) { (void)data; }

int cmp_int(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void print_int(const void* a) {
    printf("%d\n", *(const int*)a);
}

int cmp_float(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

void print_float(const void* a) {
    printf("%f\n", *(const float*)a);
}

int cmp_double(const void* a, const void* b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

void print_double(const void* a) {
    printf("%lf\n", *(const double*)a);
}

int cmp_char_ptr(const void* a, const void* b) {
    const char* sa = *(const char* const*)a;
    const char* sb = *(const char* const*)b;
    return strcmp(sa, sb);
}

void print_char_ptr(const void* a) {
    printf("%s\n", *(const char* const*)a);
}

int cmp_long(const void* a, const void* b) {
    long la = *(const long*)a;
    long lb = *(const long*)b;
    return (la > lb) - (la < lb);
}

void print_long(const void* a) {
    printf("%ld\n", *(const long*)a);
}

int cmp_unsigned_int(const void* a, const void* b) {
    unsigned int ua = *(const unsigned int*)a;
    unsigned int ub = *(const unsigned int*)b;
    return (ua > ub) - (ua < ub);
}

void print_unsigned_int(const void* a) {
    printf("%u\n", *(const unsigned int*)a);
}