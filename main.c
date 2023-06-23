#include <stdio.h>
#include <stdlib.h>

#include <collections/vec.h>


/*!
 * @brief does nothing
 * @param asdf: nothing
 */

typedef struct p2d {
    int x;
    int y;
} p2d;



int main() {
    printf("hello\n");
    int* numbers = vec_new(int, 1);
    float* decimals = vec_new(float, 3);

    void print_int(void* num) {
       printf("%d", *((int*)num));
    }

    vec_push(numbers, 1);
    vec_print(numbers, print_int, sizeof(int));
    vec_push(numbers, 2);
    vec_print(numbers, print_int, sizeof(int));
    vec_push(numbers, 3);
    vec_print(numbers, print_int, sizeof(int));
    vec_push(numbers, 4);
    vec_print(numbers, print_int, sizeof(int));
    vec_push(numbers, 5);
    vec_print(numbers, print_int, sizeof(int));
    vec_push(numbers, 6);
    vec_print(numbers, print_int, sizeof(int));

    void print_d(void* num) {
       printf("%f", *((float*)num));
    }

    vec_push(decimals, 1.f);
    vec_print(decimals, print_d, sizeof(int));
    vec_push(decimals, 2.f);
    vec_print(decimals, print_d, sizeof(int));
    vec_push(decimals, 3.f);
    vec_print(decimals, print_d, sizeof(int));
    vec_pop(decimals);
    vec_print(decimals, print_d, sizeof(int));
    vec_push(decimals, 4.f);
    vec_print(decimals, print_d, sizeof(int));
    vec_push(decimals, 5.f);
    vec_print(decimals, print_d, sizeof(int));
    vec_push(decimals, 6.f);
    vec_print(decimals, print_d, sizeof(int));




    printf("\n");
    vec_free(decimals);
    vec_free(numbers);


    return 0;
}

