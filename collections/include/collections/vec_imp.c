#include <stdlib.h>
#include <stdio.h>

#ifdef VEC_IMP

generic(vec) generic(v_new)(size_t capacity) 
{
    generic(vec) self;

    self.arr = malloc(sizeof( generic(vec) ) * capacity);
    self.capacity = capacity;
    self.length = 0;

    return self;
}


generic(vec) generic(v_from)(type arr[], size_t len)
{
    generic(vec) self;

    self.arr = malloc(sizeof( generic(vec) ) * len);
    for (size_t i = 0; i < len; i++) {
        self.arr[i] = arr[i];
    }
    self.capacity = len;
    self.length = len;

    return self;
}

type generic(v_at)(generic(vec) * self, size_t at)
{

    return (self->arr)[at];
}

void generic(v_push)(generic(vec) * self, type val)
{
    if (self->length == self->capacity) {
        self->capacity *= 2;
        self->arr = realloc(self->arr, sizeof( type ) * self->capacity);
    } 
    self->length += 1;
    (self->arr)[self->length] = val;
}

void generic(v_free)(generic(vec) * self) 
{
    free(self->arr);
    self->arr = nullptr;
}

#else

typedef struct generic(vec) {
    type * arr;
    size_t capacity;
    size_t length;
} generic(vec);

/**
 * @brief Construct a new vector with capacity
 * @param capacity: Number of elements to allocate on the heap
 * @returns Newly constructed vector
 */
generic(vec) generic(v_new)(size_t capacity);

/**
 * @brief Construct a new vector from array
 * @param arr: Array to initialize with
 * @returns Newly constructed vector
 */
generic(vec) generic(v_from)(type arr[], size_t len);


/**
 * @brief Construct a new vector from array
 * @param arr: Array to initialize with
 * @returns Newly constructed vector
 */
type generic(v_at)(generic(vec) * self, size_t at);


/**
 * @brief Push value to end of array
 * @param val: Value to be pushed to back of vector
 */
void generic(v_push)(generic(vec) * self, type val);

/**
 * @brief Free memory allocated by a vector
 * @param arr: Vector to be freed
 */
void generic(v_free)(generic(vec) * self);

#endif
