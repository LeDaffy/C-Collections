#include <stdio.h>

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

    vec_push(x, 0 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 1 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 2 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 3 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 4 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 5 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 6 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 7 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 8 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 9 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));
    vec_push(x, 10 );
    printf("Length: %d, Capacity %d\n", vec_length(x), vec_capacity(x));

    return 0;
}
