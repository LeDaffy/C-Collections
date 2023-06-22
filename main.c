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

int main() {
    vec_int x = v_new_int(5);
    x.arr[0] = 3;
    x.arr[1] = 9;
    x.arr[2] = 7;
    x.arr[3] = 1;
    x.length = 4;

    v_push_int(&x, 4);
    v_push_int(&x, 4);
    v_push_int(&x, 4);
    v_push_int(&x, 4);
    v_push_int(&x, 4);
    v_push_int(&x, 4);
    v_push_int(&x, 4);

    vec_double y = v_from_double((double[]){1.0, 2.0, 4.0, 6.2}, 4);

    vec_int_ptr z = v_new_int_ptr(5);
    z.arr[0] = &x.arr[0];
    z.arr[1] = &x.arr[1];
    z.arr[2] = &x.arr[2];
    z.arr[3] = &x.arr[3];
    z.length = 4;
    






    for (int i = 0; i < x.length; i++) {
        printf("%d %f\n", v_at_int(&x, i), v_at_double(&y, i));
    }

    say();


    printf("Hello \n");
    v_free_int(&x);
    return 0;
}
