#include <collections/d_string.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char* dstr_new(const char* str, size_t length)
{
    d_string* head = malloc(sizeof(d_string) + (sizeof(char) * length) + 1);
    if (head == NULL) {abort();}
    head->length = length;
    head->capacity = length;

    char* buf = (char*)((&(head->capacity)) + 1);
    memcpy(buf, str, sizeof(char) * length);
    buf[length] = '\0';
    return buf;
}

char*     dstr_new_with_capacity(size_t capacity)
{
    d_string* head = malloc(sizeof(d_string) + (sizeof(char) * capacity) + 1);
    if (head == NULL) {abort();}
    head->length = 0;
    head->capacity = capacity;

    char* buf = (char*)((&(head->capacity)) + 1);
    buf[0] = '\0';
    return buf;
}

char* dstr_new_nt(const char* const str)
{
    size_t length = strlen(str);
    d_string* head = malloc(sizeof(d_string) + (sizeof(char) * length) + 1);
    if (head == NULL) {abort();}
    head->length = length;
    head->capacity = length;

    char* buf = (char*)((&(head->capacity)) + 1);
    memcpy(buf, str, sizeof(char) * length);
    buf[length] = '\0';
    return buf;
}

d_string* dstr_head(const char* const str)
{
    return (d_string*)(((size_t*)str) - 2);
}

void dstr_free(const char* const str)
{
    free(dstr_head(str));
}

size_t dstr_len(const char* const str)
{
    return dstr_head(str)->length;
}

char* dstr_buf(const d_string* const head)
{
    return (char*)(((size_t*)(&(head->capacity))) + 1);
}

void dstr_cat_nt(char** str, const char* const src)
{
    size_t str_len = dstr_head(*str)->length;
    size_t str_capacity = dstr_head(*str)->capacity;
    size_t src_len = strlen(src);

    if (str_capacity < str_len + src_len) {
        d_string* head = dstr_head(*str);
        head = realloc(head, sizeof(d_string) + str_len + src_len + 1);
        if (head == NULL) {abort();}
        head->capacity = str_len + src_len;
        head->length = str_len + src_len;


        *str = dstr_buf(head);
        memcpy(&((*str)[str_len]), src, src_len);
        (*str)[str_len + src_len] = '\0';


    } else {
        memcpy(&(str[str_len]), src, src_len);
        (*str)[str_len + src_len] = '\0';
    }
}


void dstr_cat_dstr(char** str, const char* const src)
{
    size_t str_len = dstr_head(*str)->length;
    size_t str_capacity = dstr_head(*str)->capacity;
    size_t src_len = dstr_head(src)->length;

    if (str_capacity < str_len + src_len) {
        d_string* head = dstr_head(*str);
        head = realloc(head, sizeof(d_string) + str_len + src_len + 1);
        if (head == NULL) {abort();}
        head->capacity = str_len + src_len;
        head->length = str_len + src_len;


        *str = dstr_buf(head);
        memcpy(&((*str)[str_len]), src, src_len);
        (*str)[str_len + src_len] = '\0';


    } else {
        memcpy(&(str[str_len]), src, src_len);
        (*str)[str_len + src_len] = '\0';
    }
}


size_t dstr_size(const char* const str)
{
    return dstr_head(str)->length;
}
size_t dstr_capacity(const char* const str)
{
    return dstr_head(str)->capacity;
}


char* dstr_from_file(const char * filename)
{
    FILE* fp = fopen(filename, "r");
    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* file_str = dstr_new_with_capacity(file_size);
    dstr_head(file_str)->length = file_size;
    fread (file_str, 1, file_size, fp);
    file_str[file_size] = '\0';

    fclose(fp);
    return file_str;
}
