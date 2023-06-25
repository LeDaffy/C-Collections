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


char* dstr_new_nt(const char* const str)
{
    size_t length = strlen(str);
    printf("Length: %ld\n", length);
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
        memcpy(&((*str)[str_len]), src, str_len + src_len);
        (*str)[str_len + src_len] = '\0';


    } else {
        memcpy(&(str[str_len]), src, src_len);
    }
}
