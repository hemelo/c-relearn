//
// Created by henri on 07.03.2023.
//

#include <stdlib.h>
#include "binary_tree.h"

tree search(tree t, int key) {

    if (t == NULL) return NULL;

    if (t->info == key) {
        return t;
    } else if(t->info < key) {
        return search(t->right, key);
    } else {
        return search(t->left, key);
    }
}

void insert (tree * t, int key) {

    if (*t == NULL) {
        *t = (tree) malloc(sizeof(node));
        (*t)->info = key;
        (*t)->right = NULL;
        (*t)->left = NULL;
    } else if ((*t)->info > key) {
        insert((&(*t)->right), key);
    } else {
        insert((&(*t)->left), key);
    }

    return;
}