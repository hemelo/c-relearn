#include <stdio.h>

#include "./utils/math.h";

int main() {
    dynarray multiples_of_3 = get_multiples_of(3, 1000);
    dynarray multiples_of_5 = get_multiples_of(5, 1000);

    return 0;
}

