//
// Created by henri on 05.03.2023.
//

#ifndef UNTITLED_DYN_ARRAY_H
#define UNTITLED_DYN_ARRAY_H

typedef struct dynarray {
    int *array;
    int size;
} dynarray;

void push(dynarray* dyn_array, int item);

#endif //UNTITLED_DYN_ARRAY_H
