//
// Created by henri on 07.03.2023.
//

#ifndef UNTITLED_N_ARY_TREE_H
#define UNTITLED_N_ARY_TREE_H


typedef struct node {
    void * data;
    struct node * child, * next, * parent;
} node, * tree;

node * create_node(void *);
void add_sibling(node *, node *);
void add_child(node *, node *);
void new_root(node **, node *);
void remove_node(node *, node *);
int node_is_root(node * n);
int node_total(node * n);
void node_free(node * n);
node * node_find(node *, void *, int (*)(void *, void *));

#endif //UNTITLED_N_ARY_TREE_H
