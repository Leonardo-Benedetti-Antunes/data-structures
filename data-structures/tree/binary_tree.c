#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    void* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

struct BinaryTree {
    TreeNode* root;
    size_t size;
    void (*free_func)(void*);
    void (*print_func)(const void*);
};

BinaryTree* binary_tree_create(void (*free_func)(void*), void (*print_func)(const void*)) {
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    if (!tree) return NULL;
    tree->root = NULL;
    tree->size = 0;
    tree->free_func = free_func;
    tree->print_func = print_func;
    return tree;
}

void destroy_nodes(TreeNode* node, void (*free_func)(void*)) {
    if (!node) return;
    destroy_nodes(node->left, free_func);
    destroy_nodes(node->right, free_func);
    if (free_func) free_func(node->data);
    free(node);
}

void binary_tree_destroy(BinaryTree* tree) {
    if (!tree) return;
    destroy_nodes(tree->root, tree->free_func);
    free(tree);
}

TreeNode* create_node(void* data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (!node) return NULL;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void binary_tree_insert_left(TreeNode* parent, void* data) {
    if (!parent) return;
    if (parent->left) return;
    parent->left = create_node(data);
}

void binary_tree_insert_right(TreeNode* parent, void* data) {
    if (!parent) return;
    if (parent->right) return;
    parent->right = create_node(data);
}

void preorder(const TreeNode* node, void (*print_func)(const void*)) {
    if (!node) return;
    if (print_func) print_func(node->data);
    preorder(node->left, print_func);
    preorder(node->right, print_func);
}

void binary_tree_preorder(const TreeNode* node) {
    if (!node) return;
    preorder(node, NULL);
}

void inorder(const TreeNode* node, void (*print_func)(const void*)) {
    if (!node) return;
    inorder(node->left, print_func);
    if (print_func) print_func(node->data);
    inorder(node->right, print_func);
}

void binary_tree_inorder(const TreeNode* node) {
    if (!node) return;
    inorder(node, NULL);
}

void postorder(const TreeNode* node, void (*print_func)(const void*)) {
    if (!node) return;
    postorder(node->left, print_func);
    postorder(node->right, print_func);
    if (print_func) print_func(node->data);
}

void binary_tree_postorder(const TreeNode* node) {
    if (!node) return;
    postorder(node, NULL);
}

TreeNode* binary_tree_get_root(const BinaryTree* tree) {
    if (!tree) return NULL;
    return tree->root;
}

size_t count_nodes(const TreeNode* node) {
    if (!node) return 0;
    return 1 + count_nodes(node->left) + count_nodes(node->right);
}

size_t binary_tree_size(const BinaryTree* tree) {
    if (!tree) return 0;
    return count_nodes(tree->root);
}

void print_nodes(const TreeNode* node, void (*print_func)(const void*)) {
    if (!node) return;
    print_nodes(node->left, print_func);
    if (print_func) print_func(node->data);
    print_nodes(node->right, print_func);
}

void binary_tree_print(const BinaryTree* tree) {
    if (!tree || !tree->print_func) return;
    print_nodes(tree->root, tree->print_func);
}
