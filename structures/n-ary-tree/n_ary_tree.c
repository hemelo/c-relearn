//
// Created by henri on 07.03.2023.
//

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include "n_ary_tree.h"

node * create_node(char * info) {

    node * new_node = malloc(sizeof(node));

    if (new_node) {
        new_node->parent = NULL;
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->info = info;
    }

    return new_node;
}

void add_sibling(node * n, node * m) {

    if (n == NULL) return;

    while(n->next) {
        n = n->next;
    }

    n->next = m;
}

void add_child(node * n, node * m) {

    if (n == NULL) return;

    if (n->child) {
        add_sibling(n->child, m);
        m->parent = n;
    } else {
        m->parent = n;
        n->child = m;
    }
}

void new_root(node ** root, node * new_root) {

    *root = new_root;

    // ensures that new root is not a node
    remove_node(new_root->parent, new_root);

    // remove leafs
    remove_node(new_root->next, new_root);
}

void remove_node(node * n, node * new_root) {

    if (n->next != NULL)
        remove_node(n->next, new_root);

    if (n->child != NULL && n->child != new_root)
        remove_node(n->child, new_root);

    free(n);
}

int node_is_root(node * n) {
    if (n->parent == NULL)
        return TRUE;
    else
        return FALSE;
}

