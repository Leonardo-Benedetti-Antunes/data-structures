#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

typedef struct TreeNode TreeNode;
typedef struct BinaryTree BinaryTree;

BinaryTree* binary_tree_create(
    void (*free_func)(void*),
    void (*print_func)(const void*)
);
void binary_tree_destroy(BinaryTree* tree);

void binary_tree_insert_left(TreeNode* parent, void* data);
void binary_tree_insert_right(TreeNode* parent, void* data);

void binary_tree_preorder(const TreeNode* node);
void binary_tree_inorder(const TreeNode* node);
void binary_tree_postorder(const TreeNode* node);

TreeNode* binary_tree_get_root(const BinaryTree* tree);
size_t binary_tree_size(const BinaryTree* tree);

void binary_tree_print(const BinaryTree* tree);

#endif
