#include <stdio.h>
#include <collections/vec.h>

void say() {
    vec_double x = v_from_double((double[]){1.3, 20.4, 10.2}, 3);
    for (int i = 0; i < x.length; i++) {
        printf("%f\n", v_at_double(&x, i));

    }

    return;
}
