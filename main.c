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

void vec_print(int* arr) {
    vec* head = vec_head(arr);
    printf("Size: %ld Capacity: %ld Vals: {", head->length, head->capacity);
    for (int* ptr = vec_iter(arr); ptr < vec_iter_end(arr); ptr++) {
        printf("%d, ", *ptr);
    }


    printf("}\n");
    return;
}

void vec_print_f(float* arr) {
    vec* head = vec_head(arr);
    printf("Size: %ld Capacity: %ld Vals: {", head->length, head->capacity);
    for (float* ptr = vec_iter(arr); ptr < vec_iter_end(arr); ptr++) {
        printf("%f, ", *ptr);
    }


    printf("}\n");
    return;
}


int main() {
    printf("hello\n");
    int* numbers = vec_new(int, 1);
    float* decimals = vec_new(float, 3);

    vec_push(numbers, 1);
    vec_print(numbers);
    vec_push(numbers, 2);
    vec_print(numbers);
    vec_push(numbers, 3);
    vec_print(numbers);
    vec_push(numbers, 4);
    vec_print(numbers);
    vec_push(numbers, 5);
    vec_print(numbers);
    vec_push(numbers, 6);
    vec_print(numbers);


    vec_push(decimals, 1.f);
    vec_print_f(decimals);
    vec_push(decimals, 2.f);
    vec_print_f(decimals);
    vec_push(decimals, 3.f);
    vec_print_f(decimals);
    vec_pop(decimals);
    vec_print_f(decimals);
    vec_push(decimals, 4.f);
    vec_print_f(decimals);
    vec_push(decimals, 5.f);
    vec_print_f(decimals);
    vec_push(decimals, 6.f);
    vec_print_f(decimals);


    printf("\n");
    return 0;
}

