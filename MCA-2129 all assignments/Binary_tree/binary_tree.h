#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int data);
struct Node *delete_node(struct Node *root, int data);
void inorder_traversal(struct Node *root);
void free_tree(struct Node *root);
#endif
