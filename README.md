
# Generic Linked Lists in C

This project provides a generic implementation of singly and doubly linked lists in the C programming language. It supports storage of any data type through the use of void pointers and user-defined callback functions for memory management, comparison, and printing.

## Project Structure

- `singly_linked_list.h/.c`: Implementation of **singly linked list**.
- `doubly_linked_list.h/.c`: Implementation of **doubly linked list**.
- `common_callbacks.h/.c`: Utility callback functions for primitive types (int, float, etc.).
- `singly_linked_list_factory.h/.c`: Factory functions for singly linked lists using predefined callbacks.
- `doubly_linked_list_factory.h/.c`: Factory functions for doubly linked lists using predefined callbacks.

---

## Compilation

```bash
gcc -o main main.c singly_linked_list.c doubly_linked_list.c \
    singly_linked_list_factory.c doubly_linked_list_factory.c common_callbacks.c
```

Or compile as a library and include it in your project.

---

## Usage Example (Singly Linked List with `int`)

```c
#include "singly_linked_list_factory.h"

int main() {
    SinglyLinkedList* list = s_create_int_list();

    int* a = malloc(sizeof(int));
    *a = 10;
    s_linked_list_insert_back(list, a);

    int* b = malloc(sizeof(int));
    *b = 20;
    s_linked_list_insert_back(list, b);

    s_linked_list_print(list);
    s_linked_list_destroy(list);
    return 0;
}
```

---

## Usage Example (Doubly Linked List with a Struct)

```c
#include "doubly_linked_list.h"

typedef struct {
    int id;
    char name[32];
} Person;

int cmp_person(const void* a, const void* b) {
    const Person* pa = a;
    const Person* pb = b;
    return (pa->id > pb->id) - (pa->id < pb->id);
}

void print_person(const void* a) {
    const Person* p = a;
    printf("ID: %d, Name: %s\n", p->id, p->name);
}

void free_person(void* a) {
    free(a);
}

int main() {
    DoublyLinkedList* list = d_linked_list_create(free_person, cmp_person, print_person);

    Person* p1 = malloc(sizeof(Person));
    p1->id = 1; strcpy(p1->name, "Alice");

    Person* p2 = malloc(sizeof(Person));
    p2->id = 2; strcpy(p2->name, "Bob");

    d_linked_list_insert_back(list, p1);
    d_linked_list_insert_back(list, p2);

    d_linked_list_print(list);
    d_linked_list_destroy(list);
    return 0;
}
```

---

## Available Functions

### Creation
```c
SinglyLinkedList* s_linked_list_create(free_func, cmp_func, print_func);
DoublyLinkedList* d_linked_list_create(free_func, cmp_func, print_func);
```

Factory methods:
```c
SinglyLinkedList* s_create_int_list();
DoublyLinkedList* d_create_float_list();
// Also available: double, char*, long, unsigned int
```

### Insertion
```c
void s_linked_list_insert_front(...);
void s_linked_list_insert_back(...);
void d_linked_list_insert_front(...);
void d_linked_list_insert_back(...);
```

### Appending Lists
```c
void s_linked_list_append_front(...);
void s_linked_list_append_back(...);
void d_linked_list_append_front(...);
void d_linked_list_append_back(...);
```

### Removal and Access
```c
int s_linked_list_remove(...);
size_t s_linked_list_size(...);
void s_linked_list_print(...);

// Equivalent functions for doubly linked lists are also available.
```

---

## Custom Callbacks

You may define your own comparison, printing, and freeing functions and provide them during list creation.

Example:
```c
int cmp_my_type(const void* a, const void* b) { ... }
void print_my_type(const void* data) { ... }
void free_my_type(void* data) { ... }

SinglyLinkedList* list = s_linked_list_create(free_my_type, cmp_my_type, print_my_type);
```

---

## License

This project is intended for educational use and is free to reuse for academic and personal purposes.
