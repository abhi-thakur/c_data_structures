#include "array_list.h"
#include <string.h>
#include <stdio.h>

#define INITIAL_CAP 10

struct list {
    size_t  len;
    size_t  cap;
    size_t  elem_size;
    void**  data;
};

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

void arr_lst_set(array_list* lst, size_t index, void* item) {
    if (index < 0 || index >= lst->len) return;

    lst->data[index] = item;
}

void* arr_lst_pop(array_list* lst) {
    if (lst->len == 0) {
        return NULL;
    }

    void* item = lst->data[--lst->len];
    lst->data[lst->len] = NULL;

    return item;
}

void arr_lst_insert(array_list* lst, size_t index, void* item) {
    if (index < 0 || index >= lst->len) return;

    __ensure_cap(lst);

    // shift elements by one place to right from the index
    void** dst = lst->data + index + 1;
    void** src = lst->data + index;
    memmove(dst, src, lst->elem_size * (lst->len - index));

    lst->data[index] = item;
    lst->len++;
}

void arr_lst_rm(array_list* lst, size_t index) {
    if (index < 0 || index >= lst->len) return;

    size_t new_len;
    if ((new_len = lst->len - 1) > index) {
        void** dst = lst->data + index;
        void** src = lst->data + index + 1;
        memmove(dst, src, (lst->len - (index + 1)) * lst->elem_size);
    }

    lst->data[lst->len = new_len] = NULL;
}

void arr_lst_clr(array_list* lst) {
    size_t elem_sz = lst->elem_size;
    arr_lst_des(lst);

    *lst = *arr_lst_new(elem_sz);
}

void* arr_lst_get(array_list* lst, size_t index) {
    if (index < 0 || index > lst->len - 1) {
        return NULL;
    }

    return lst->data[index];
}

int arr_lst_indexof(array_list* lst, void* item, int (*fn_ptr)(void*, void*)) {
    if (fn_ptr != NULL) {
        // sequential search
        for (size_t i = 0; i < lst->len; i++) {
            if (fn_ptr(item, lst->data[i])) {
                return i;
            }
        }
    }

    return -1;
}

extern inline size_t arr_lst_size(array_list* lst) {
    return lst->len;
}

extern inline size_t arr_lst_cap(array_list* lst) {
    return lst->cap;
}
