#include <stdio.h>

#include <collections/vec.h>

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
    x.array[0] = 3;
    x.array[1] = 9;
    x.array[2] = 7;
    x.array[3] = 1;
    x.length = 4;

    vec_double y = v_new_double(5);
    y.array[0] = 2.71;
    y.array[1] = 93.1;
    y.array[2] = 239.1;
    y.array[3] = 28.302;
    y.length = 4;

    vec_int_ptr z = v_new_int_ptr(5);
    z.array[0] = &x.array[0];
    z.array[1] = &x.array[1];
    z.array[2] = &x.array[2];
    z.array[3] = &x.array[3];
    z.length = 4;
    






    for (int i = 0; i < x.length; i++) {
        printf("%d %f\n", *(z.array[i]), y.array[i]);
    }

    printf("Hello \n");
    v_free_int(&x);
    return 0;
}
