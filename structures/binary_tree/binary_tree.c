//
// Created by henri on 07.03.2023.
//

#define TRUE 1
#define FALSE 0

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

int exclude(tree * t, int key) {
    tree u;

    if (*t == NULL) {
        return FALSE;
    } else if ( key < (*t)->info) {
        exclude(&((*t)->left), key);
    } else if ( key > (*t)->info) {
        exclude(&((*t)->right), key);
    } else {
        u = *t;

        if (u->right == NULL) {
            *t = u->left;
        } else if (u->left == NULL) {
            *t = u->right;
        } else {
            delete(&u, &(u->left));
        }

        free(u);
    }

    return TRUE;
}

void delete(tree * t, tree * u) {
    if ((*u)->right != NULL) {
        delete(t, &((*u)->left));
    } else {
        (*u)->info = (*t)->info;
        (*t) = *u;
        *u = (*u)->left;
    }
}

int highest_key(tree t) {
    int highest;
    highest = t->info;

    while (t != NULL) {
        highest = t->info;
        t = t->right;
    }

    return highest;
}

int lowest_key(tree t) {
    int lowest;
    lowest = t->info;

    while (t != NULL) {
        lowest = t->info;
        t = t->left;
    }

    return lowest;
}