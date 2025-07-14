# Generic Data Structures in C

This project provides generic implementations of fundamental data structures in the C programming language, including:

- Singly and doubly linked lists
- FIFO and priority queues
- Stacks
- Binary trees

All structures support storage of any data type through the use of `void*` pointers and user-defined callback functions for memory management, comparison, and printing.

---

## 📁 Project Structure

### Linked Lists

- `singly_linked_list.h/.c`: **Singly linked list** implementation.
- `doubly_linked_list.h/.c`: **Doubly linked list** implementation.
- `singly_linked_list_factory.h/.c`: Factory functions for singly linked lists with predefined callbacks.
- `doubly_linked_list_factory.h/.c`: Factory functions for doubly linked lists with predefined callbacks.

### Queues

- `queue.h/.c`: **FIFO queue** implementation using singly linked list.
- `priority_queue.h/.c`: **Priority queue** implementation using linked list.
- `queue_factory.h/.c`: Factory functions for FIFO queues.
- `priority_queue_factory.h/.c`: Factory functions for priority queues.

### Stacks

- `stack.h/.c`: **Stack** implementation using linked list.
- `stack_factory.h/.c`: Factory functions for stacks with predefined callbacks.

### Trees

- `binary_tree.h/.c`: **Binary tree** implementation using linked nodes.
- `binary_tree_factory.h/.c`: Factory functions for binary trees with predefined callbacks.

### Common Utilities

- `common_callbacks.h/.c`: Callback functions for primitive types (int, float, double, char\*, long, unsigned int).

---

## 🛠️ Compilation Example

```bash
gcc -o main main.c \
linked-list/*.c queue/*.c stack/*.c tree/*.c common-callbacks/*.c
```

Or compile each module as a library and include it in your project.

---

## 💡 Usage Examples

### Singly Linked List (int)

```c
#include "singly_linked_list_factory.h"

int main() {
    SinglyLinkedList* list = s_create_int_list();
    int* a = malloc(sizeof(int)); *a = 10;
    s_linked_list_insert_back(list, a);
    s_linked_list_print(list);
    s_linked_list_destroy(list);
    return 0;
}
```

### FIFO Queue (int)

```c
#include "queue_factory.h"

int main() {
    Queue* q = queue_create_int();
    int* a = malloc(sizeof(int)); *a = 5;
    queue_enqueue(q, a);
    queue_print(q);
    queue_destroy(q);
    return 0;
}
```

### Priority Queue (int)

```c
#include "priority_queue_factory.h"

int main() {
    PriorityQueue* pq = priority_queue_create_int(0, 100, 1);
    int* a = malloc(sizeof(int)); *a = 99;
    priority_queue_enqueue(pq, a, 3);
    priority_queue_print(pq);
    priority_queue_destroy(pq);
    return 0;
}
```

### Doubly Linked List (struct)

```c
#include "doubly_linked_list.h"
#include <string.h>

typedef struct { int id; char name[32]; } Person;

int cmp_person(const void* a, const void* b) {
    return ((Person*)a)->id - ((Person*)b)->id;
}
void print_person(const void* a) {
    printf("ID: %d, Name: %s\n", ((Person*)a)->id, ((Person*)a)->name);
}
void free_person(void* a) { free(a); }

int main() {
    DoublyLinkedList* list = d_linked_list_create(free_person, cmp_person, print_person);
    Person* p = malloc(sizeof(Person)); p->id = 1; strcpy(p->name, "Alice");
    d_linked_list_insert_back(list, p);
    d_linked_list_print(list);
    d_linked_list_destroy(list);
    return 0;
}
```

### Stack (int)

```c
#include "stack_factory.h"

int main() {
    Stack* stack = stack_create_int();
    int* a = malloc(sizeof(int)); *a = 42;
    stack_push(stack, a);
    stack_print(stack);
    stack_destroy(stack);
    return 0;
}
```

### Binary Tree (int)

```c
#include "binary_tree_factory.h"

int main() {
    BinaryTree* tree = binary_tree_create_int();
    tree->root = malloc(sizeof(TreeNode));
    tree->root->data = malloc(sizeof(int)); *(int*)tree->root->data = 10;
    tree->root->left = NULL; tree->root->right = NULL;
    binary_tree_insert_left(tree->root, malloc(sizeof(int)));
    *(int*)tree->root->left->data = 5;
    binary_tree_insert_right(tree->root, malloc(sizeof(int)));
    *(int*)tree->root->right->data = 20;
    binary_tree_print(tree);
    binary_tree_destroy(tree);
    return 0;
}
```

---

## 🔎 Available Functions

### ✅ Creation

- Lists, Queues, Stacks, Binary Trees (with or without factory helpers).

### ✅ Insertion & Removal

- Insert front/back, enqueue, push, tree insertion (left/right).
- Pop, dequeue, remove elements.

### ✅ Traversal

- Linked list iteration, queue printing.
- Tree preorder, inorder, postorder traversals.

### ✅ Utilities

- Size checks, is\_empty checks, print functions, custom callbacks.

---

## 🖋️ Custom Callbacks

You can provide your own comparison, printing, and freeing functions during initialization to fully customize behavior.

---

## 📝 License

This project is intended for educational use and is free to reuse for academic and personal purposes.