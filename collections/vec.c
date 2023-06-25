#include <collections/vec.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void* vec_impl_new(size_t capacity, size_t data_size)
void* vec_impl_new(size_t capacity, size_t data_size) 
{
    vec* head = malloc(sizeof(vec) + (data_size * capacity));
    if (head == NULL) {abort();}
    head->length = 0;
    head->capacity = capacity;

    return (void*)((&(head->capacity)) + 1);
}

void* vec_impl_from(void* buf, size_t length, size_t data_size)
{
    vec* head = malloc(sizeof(vec) + (data_size * length));
    if (head == NULL) {abort();}
    head->length = length;
    head->capacity = length;
    void* arr = ((&(head->capacity)) + 1);

    memcpy(arr, buf, data_size * length);
    return arr;


}

vec* vec_head(void* buf) 
{
    return (vec*)(((size_t*)buf) - 2);
}

void vec_pop(void* buf)
{
    vec_head(buf)->length -= 1;
}

void* vec_buf(vec* head) {
    return (void*)((&(head->capacity)) + 1);
}

void vec_free(void* buf)
{
    free(vec_head(buf));
}


size_t vec_size(void* buf) 
{
    return vec_head(buf)->length;
}

size_t vec_length(void* buf) 
{
    return vec_head(buf)->length;
}

size_t vec_capacity(void* buf) 
{
    return vec_head(buf)->capacity;
}

void vec_print(void* buf, void (*print)(void*), size_t data_size) 
{
    vec* head = vec_head(buf);
    printf("Size: %ld\tCapacity: %ld\t Buffer: {", head->length, head->capacity);
    for (int i = 0; i < head->length; i++) {
        (*print)(buf + (i * data_size));
        printf(", ");
    }
    printf("}\n");
}

void vec_impl_push(void** buf, size_t data_size)
{
    if (vec_size(*buf) == vec_capacity(*buf)) {
        vec* head = vec_head(*buf);
        
        /* reallocate vector twice the size */
        head = realloc(head, sizeof(vec) + data_size*(2 * vec_capacity(*buf)));
        if (head == NULL) {abort();}
        head->capacity *= 2;
        head->length += 1;


        *buf = vec_buf(head);
    } else {
        vec* head = vec_head(*buf);
        head->length += 1;
    }
}
