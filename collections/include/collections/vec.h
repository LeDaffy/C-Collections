#pragma once
#include <stdlib.h>


#define generic(name) name ## _ ## int
#define type int
#include <collections/vec_imp.c>
#undef generic
#undef type

#define generic(name) name ## _ ## double
#define type double
#include <collections/vec_imp.c>
#undef generic
#undef type


typedef int* int_ptr;
#define generic(name) name ## _ ## int_ptr
#define type int_ptr
#include <collections/vec_imp.c>
#undef generic
#undef type

typedef struct vec {
    size_t length;
    size_t capacity;
} vec;


/**
 * type* vec_from(type*, size_t _capacity);
 */
#define vec_new(_type, _capacity) \
({ \
    vec* _self = malloc(sizeof(vec) + (sizeof(typeof(_type)) * _capacity)); \
    _self->length = 0; \
    _self->capacity = _capacity; \
    (typeof(_type)) ((&(_self->capacity)) + 1); \
})

/**
 * Used to pass comma separated arry into macro
 * ex: macro( P99_PROTECT((int[]){1, 2, 3}) )
 */
#define P99_PROTECT(...) __VA_ARGS__


/**
 * type* vec_from(type*, type[] _arr, size_t _length);
 */
#define vec_from(_type, _arr, _length) \
({ \
    vec* _self = malloc(sizeof(vec) + (sizeof(typeof(_type)) * _length)); \
    _self->length = _length; \
    _self->capacity = _length; \
    auto _temp = (typeof(_type)) ((&(_self->capacity)) + 1); \
    for (int i = 0; i < _length; i++) \
    { \
     _temp[i] = _arr[i]; \
    } \
    (typeof(_type)) ((&(_self->capacity)) + 1); \
})

/**
 * void vec_free(arr* _self);
 */
#define vec_free(self) \
({ \
    free((vec*)((size_t*)(self) - 2)); \
})

/**
 * size_t vec_length(arr* _self)
 */
#define vec_length(_self) \
({ \
 *(((size_t*)(_self)) - 2) ; \
})

/**
 * size_t vec_length(arr* _self)
 */
#define vec_capacity(_self) \
({ \
 *(((size_t*)(_self)) - 1) ; \
})

#define vec_push(_self, val) \
    if (vec_length(_self) == vec_capacity(_self)) { /* if vec is at capacity */ \
        printf("Realloc!"); \
        vec* _head = (vec*)(((size_t*)_self) - 2); \
        _head = realloc(_head, sizeof(vec) + (2 * vec_length(_self))); \
        _head->capacity *= 2; \
        _head->length += 1; \
    } else { \
        *((size_t*)(_self) - 2) += 1; \
        _self[vec_length(_self) + 1] = val; \
    }
