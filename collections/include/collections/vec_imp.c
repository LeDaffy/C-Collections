#include <stdlib.h>

#ifdef VEC_IMP

generic(vec) generic(v_new)(size_t capacity) 
{
    generic(vec) self;

    self.array = malloc(sizeof( generic(vec) ) * capacity);
    self.capacity = capacity;
    self.length = 0;

    return self;
}


generic(vec) generic(v_from)(type arr[], size_t len)
{
    generic(vec) self;

    self.array = malloc(sizeof( generic(vec) ) * len);
    for (size_t i = 0; i < len; i++) {
        self.array[i] = arr[i];
    }
    self.capacity = len;
    self.length = len;

    return self;
}

void generic(v_free)(generic(vec) * self) 
{
    free(self->array);
    self->array = nullptr;
}

#else

typedef struct generic(vec) {
    type * array;
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

void generic(v_free)(generic(vec) * self);

#endif
