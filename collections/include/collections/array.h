#pragma once


/*
 * C Type Generic Vector:
 * _____________________________
 * |  Header  |  Array Buffer  |
 * ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
 * Memory is statically allocated when using vec_new() and a pointer is returned
 * to the address of the array buffer.
 */

#define arr_new(_type, _size) \
    
