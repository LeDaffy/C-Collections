/*
 * Dynamic C String:
 * _____________________________
 * |  Header  |  String Buffer  |
 * ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
 *            ^
 * Memory is dynically allocated when using string_new() and a pointer is
 * returned to the address of the array buffer.
 */

#include <stdlib.h>

char* string_new(const char* str, size_t size);
