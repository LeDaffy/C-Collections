#include <stdio.h>
#include <stdlib.h>

#include <collections/vec.h>
#include "funs.h"


/*!
 * @brief does nothing
 * @param asdf: nothing
 */
void myfun(int asdf) {
    ;

    return;
}

typedef struct p2d {
    int x;
    int y;
} p2d;


int main() {
    int* x = vec_new(int*, 2);

    vec_push(x, 1);
    vec_push(x, 2);
    vec_push(x, 2);
    vec_push(x, 2);
    for (int i = 0; i < vec_length(x); i++) {
        printf("Value: %d\tLength: %u\t Capacity: %u\n", x[i], vec_length(x), vec_capacity(x));
    }

    return 0;
}
