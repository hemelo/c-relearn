//
// Created by henri on 07.03.2023.
//

#ifndef UNTITLED_N_ARY_TREE_H
#define UNTITLED_N_ARY_TREE_H


typedef struct node {
    char * info;
    struct node * child, * next, * parent;
    int depth, children;
} node, * tree;

node * create_node(char *);
node * add_sibling(node * n, char * data);
void new_root(node ** root, node * new_root);
void remove_node(node * n, node * new_root);

#endif //UNTITLED_N_ARY_TREE_H
