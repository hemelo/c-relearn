//
// Created by henri on 07.03.2023.
//

#ifndef UNTITLED_BINARY_TREE_H
#define UNTITLED_BINARY_TREE_H

#include <stdio.h>

typedef struct Node {
    int info;
    struct Node * left, * right
} node, * tree;

tree root = NULL;
tree search(tree, int);
void insert(tree *, int);
void print(tree, int);
int exclude(tree *, int);
void delete(tree *, tree *);
int highest_key(tree t);
int lowest_key(tree t);
void pre_order_traversal(tree t);
void post_order_traversal(tree t);
void order_traversal(tree t);

#endif //UNTITLED_BINARY_TREE_H
