/*
 * Dynamic C String:
 * _______________________________________
 * |  Header  |  String Buffer  |  '\0'  |
 * ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
 *            ^
 * Memory is dynically allocated when using string_new() and a pointer is
 * returned to the address of the array buffer.
 */

#include <stdlib.h>

typedef struct d_string {
    size_t length;
    size_t capacity;
} d_string;

char*     dstr_new(const char* str, size_t length);
char*     dstr_new_with_capacity(size_t capacity);
char*     dstr_new_nt(const char* const str);
char*     dstr_from_file(const char * filename);
d_string* dstr_head(const char* const str);
char*     dstr_buf(const d_string* const head);
void      dstr_free(const char* const str);
size_t    dstr_len(const char* const str);
void      dstr_cat_nt(char** str, const char* const src);
void      dstr_cat_dstr(char** str, const char* const src);
size_t    dstr_size(const char* const str);
size_t    dstr_capacity(const char* const str);


