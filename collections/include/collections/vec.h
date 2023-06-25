#pragma once
/*
 * C Type Generic Vector:
 * _____________________________
 * |  Header  |  Array Buffer  |
 * ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
 *            ^
 * Memory is dynically allocated when using vec_new() and a pointer is returned
 * to the address of the array buffer.
 */




#include <stdlib.h>
#include <stddef.h>


typedef struct vec {
    size_t length;
    size_t capacity;
} vec;


// Call directly
void* vec_buf(vec* head);
size_t vec_size(void* buf);
size_t vec_length(void* buf);
vec* vec_head(void* buf);
void vec_free(void* buf);
void vec_pop(void* buf);
size_t vec_capacity(void* buf);

void vec_print(void* buf, void (*print)(void*), size_t data_size);
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
void* vec_impl_from(void* buf, size_t length, size_t data_size);
#define vec_from(_arr, _length) \
({ \
    vec_impl_from(_arr, _length, sizeof(_arr[0])); \
})



/**
 * void vec_push(type* arr, _val);
 */
void vec_impl_push(void** buf, size_t data_size);
#define vec_push(_self, _val) \
    vec_impl_push((void**)(&_self), sizeof(_val)); \
    _self[vec_length(_self) - 1] = _val;


