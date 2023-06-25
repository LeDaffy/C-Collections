#include <stdio.h>
#include <stdlib.h>

#include <collections/vec.h>

/**
 * main.c:
 * Example of vector operations on different types
 */




int main() {


    // Vector of ints
    //int* numbers = vec_new(int, 1);
    //int* numbers = vec_impl_from((int[3]){100, 100, 100}, 3, sizeof(int));
    // Nested function (GCC only)
    void print_int(void* num) {
       printf("%d", *((int*)num));
    }

    int* numbers = vec_from(P99_PROTECT((int[3]){100, 100, 100}), 3);
    vec_print(numbers, print_int, sizeof(int));
    vec_pop(numbers);
    vec_print(numbers, print_int, sizeof(int));

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


    // Vector of floats
    float* decimals = vec_new(float, 3);
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

    // Vector of int[2] array
    int** arrs = vec_new(int[2], 1);
    void __fnprint(void* buf) 
    {
        printf("[%d, %d]", ((int**)buf)[0][0], ((int**)buf)[0][1]);
    }

    /* P99_PROTECT required around any macro function arguments that have
     * commas in them */
    vec_push(arrs, P99_PROTECT((int[2]){1, 2}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_push(arrs, P99_PROTECT((int[2]){3, 4}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_push(arrs, P99_PROTECT((int[2]){5, 6}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_push(arrs, P99_PROTECT((int[2]){500, 61}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_push(arrs, P99_PROTECT((int[2]){123, 2047}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_push(arrs, P99_PROTECT((int[2]){843, 92761}));
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_pop(arrs);
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_pop(arrs);
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_pop(arrs);
    vec_print(arrs, __fnprint, sizeof(int[2]));
    vec_pop(arrs);
    vec_print(arrs, __fnprint, sizeof(int[2]));




    printf("\n");
    vec_free(decimals);
    vec_free(numbers);
    vec_free(arrs);


    return 0;
}

