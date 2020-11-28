#ifndef __ARRAY_LIST
#define __ARRAY_LIST

#include <stdlib.h>

typedef struct {
    size_t  len;
    size_t  cap;
    size_t  elem_size;
    void**  data;
} array_list;

array_list*     arr_lst_new(size_t size);
void            arr_lst_des(array_list* lst);

void            arr_lst_add(array_list* lst, void* item);
void            arr_lst_set(array_list* lst, size_t index, void* item);
void*           arr_lst_pop(array_list* lst);
void            arr_lst_insert(array_list* lst, size_t index, void* item);
void            arr_lst_rm(array_list* lst, size_t index);
void            arr_lst_clr(array_list* lst);

void*           arr_lst_get(array_list* lst, size_t index);
int             arr_lst_indexof(array_list* lst, void* item, int (*fn_ptr)(void*, void*));

size_t          arr_lst_size(array_list* lst);
size_t          arr_lst_cap(array_list* lst);

#endif /* __ARRAY_LIST */
