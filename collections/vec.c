#include <collections/vec.h>

#include <stdlib.h>

//void* vec_impl_new(size_t capacity, size_t data_size)
void* vec_impl_new(size_t capacity, size_t data_size) 
{
    vec* head = malloc(sizeof(vec) + (data_size * capacity));
    if (head == NULL) {abort();}
    head->length = 0;
    head->capacity = capacity;

    return (void*)((&(head->capacity)) + 1);
}

vec* vec_head(void* arr) 
{
    return (vec*)(((size_t*)arr) - 2);
}


void* vec_arr(vec* head) {
    return (void*)((&(head->capacity)) + 1);
}

void vec_free(void* arr)
{
    free(vec_head(arr));
}


size_t vec_size(void* arr) 
{
    return vec_head(arr)->length;
}

size_t vec_length(void* arr) 
{
    return vec_head(arr)->length;
}

size_t vec_capacity(void* arr) 
{
    return vec_head(arr)->capacity;
}

void vec_impl_push(void** arr, size_t data_size)
{
    if (vec_size(*arr) == vec_capacity(*arr)) {
        vec* head = vec_head(*arr);
        
        /* reallocate vector twice the size */
        head = realloc(head, sizeof(vec) + data_size*(2 * vec_capacity(*arr)));
        if (head == NULL) {abort();}
        head->capacity *= 2;
        head->length += 1;


        *arr = vec_arr(head);
    } else {
        vec* head = vec_head(*arr);
        head->length += 1;
    }
}
