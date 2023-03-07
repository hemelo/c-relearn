//
// Created by henri on 05.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "dyn_array.h"

void push(dynarray* dyn_array, int item) {
    int last_index = dyn_array->size;

    if (dyn_array->array == NULL) {
        dyn_array->array = (int *) malloc(sizeof(int));
    } else {
        dyn_array->array = realloc(dyn_array->array, sizeof(int) * (last_index + 1));
    }

    dyn_array->array[last_index] = item;
    dyn_array->size++;
}
