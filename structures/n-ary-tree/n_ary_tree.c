//
// Created by henri on 07.03.2023.
//

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

node * add_sibling(node * n, char * data) {

    if (n == NULL) return NULL;

    while(n->next) {
        n = n->next;
    }

    n->next = create_node(data);
    return n->next;
}

node * add_child(node * n, char * data) {

    if (n == NULL) return NULL;

    if (n->child) {
        node * m = add_sibling(n->child, data);
        m->parent = n;
    } else {
        n->child = create_node(data);
        n->child->parent = n;
        return n->child;
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

