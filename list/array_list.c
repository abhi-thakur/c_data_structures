#include "array_list.h"
#include <string.h>

// non-public method
void __ensure_cap(array_list* lst) {
    size_t len = lst->len;
    size_t cap = lst->cap;

    if (len != 0 && len >= cap) {
        lst->cap = cap + (cap >> 1);
        void* new_ptr = malloc(lst->elem_size * lst->cap);
        memcpy(new_ptr, lst->data, lst->len * lst->elem_size);
        free(lst->data);
        lst->data = new_ptr;
    }
}
// non-public method

array_list* arr_lst_new(size_t size) {
    array_list* lst = (array_list*) malloc(sizeof(array_list));
    lst->cap = INITIAL_CAP;
    lst->len = 0;
    lst->data = (void**) malloc(size * INITIAL_CAP);
    lst->elem_size = size;

    return lst;
}

void arr_lst_des(array_list* lst) {
    free(lst->data);
    free(lst);
}

void arr_lst_add(array_list* lst, void* elem) {
    __ensure_cap(lst);

    lst->data[lst->len++] = elem;
}

void* arr_lst_get(array_list* lst, size_t index) {
    if (index < 0 || index > lst->len - 1) {
        return NULL;
    }

    return lst->data[index];
}

void arr_lst_rm(array_list* lst, size_t index) {
    if (index < 0 || index > lst->len - 1) {
        return;
    }

    lst->data[index] = NULL;

    if (index < lst->len - 1) {
        void** dst = lst->data + index;
        void** src = lst->data + index + 1;
        memmove(dst, src, (lst->len - (index + 1)) * lst->elem_size);
    }

    lst->len--;
}

extern inline size_t arr_lst_size(array_list* lst) {
    return lst->len;
}

extern inline size_t arr_lst_cap(array_list* lst) {
    return lst->cap;
}
