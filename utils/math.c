//
// Created by henri on 05.03.2023.
//

#include <stdlib.h>
#include "math.h"

dynarray get_multiples_of(int number, int limit) {

    dynarray dyn_array;
    dyn_array.size = 0;
    dyn_array.array = (int *) malloc(sizeof(int));

    int actual = 0;

    while((actual += number) < limit) {
        push(&dyn_array, actual);
    }

    return dyn_array;
}