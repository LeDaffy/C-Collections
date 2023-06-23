#pragma once
#include <stdlib.h>



typedef struct vec {
    size_t length;
    size_t capacity;
} vec;


// Call directly
void* vec_arr(vec* head);
size_t vec_size(void* arr);
size_t vec_length(void* arr);
vec* vec_head(void* arr);
void vec_free(void* arr);
void vec_pop(void* arr);
size_t vec_capacity(void* arr);
#define vec_iter(_self) \
    ({_self;})
#define vec_iter_end(_self) \
    ({_self + vec_size(_self);})


// Call through macros
__attribute__ ((malloc, malloc (vec_free))) 
void* vec_impl_new(size_t capacity, size_t data_size);
#define vec_new(_type, _capacity) \
({ \
 vec_impl_new(_capacity, sizeof(_type)); \
}) \



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
 * void vec_push(type* arr, _val);
 */
void vec_impl_push(void** arr, size_t data_size);
#define vec_push(_self, _val) \
    vec_impl_push((void**)(&_self), sizeof(_val)); \
    _self[vec_length(_self) - 1] = _val;


