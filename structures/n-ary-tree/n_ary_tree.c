//
// Created by henri on 07.03.2023.
//

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include "n_ary_tree.h"

node * create_node(void * data) {

    node * new_node = malloc(sizeof(node));

    if (new_node) {
        new_node->parent = NULL;
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->data = data;
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

    if (n->next)
        remove_node(n->next, new_root);

    if (n->child && n->child != new_root)
        remove_node(n->child, new_root);

    free(n);
}

int node_is_root(node * n) {
    if (n->parent == NULL)
        return TRUE;
    else
        return FALSE;
}

int node_total(node * n) {

    if (n == NULL) return 0;

    int t = 1;

    if (n->child)
        t += node_total(n->child);

    if (n->next)
        t += node_total(n->next);

    return t;
}

void node_free(node * n) {

    if (n == NULL) return;

    if (n->child)
        node_free(n->child);

    if (n->next)
        node_free(n->next);

    free(n);
}

node * node_find(node * n, void * data, int (*compare)(void *a, void *b)) {

    if (n == NULL)
        return NULL;

    if (compare(data, n->data))
        return n;

    if (n->next)
        return node_find(n->next, data, compare);

    if (n->next)
        return node_find(n->next, data, compare);

    return NULL;
}



