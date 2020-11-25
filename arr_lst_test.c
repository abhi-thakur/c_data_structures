// #define NDEBUG

#include <assert.h>
#include "list/array_list.h"

int main() {
    void* a = (void*)10;
	void* b = (void*)20;
	void* c = (void*)30;
	void* d = (void*)40;
	void* e = (void*)50;
	void* f = (void*)60;

    size_t int_size = sizeof(int);
    array_list* num_lst = arr_lst_new(int_size);

    assert(arr_lst_size(num_lst) == 0);
    assert(arr_lst_cap(num_lst) == 10);

    arr_lst_add(num_lst, a);
    arr_lst_add(num_lst, b);

    assert(arr_lst_size(num_lst) == 2);

    assert(arr_lst_get(num_lst, 0) == a);
    assert(arr_lst_get(num_lst, 1) == b);

    arr_lst_add(num_lst, c);
    arr_lst_add(num_lst, d);

    assert(arr_lst_size(num_lst) == 4);
    assert(arr_lst_cap(num_lst) == 10);

    assert(arr_lst_get(num_lst, 0) == a);
    assert(arr_lst_get(num_lst, 1) == b);
    assert(arr_lst_get(num_lst, 2) == c);
    assert(arr_lst_get(num_lst, 3) == d);

    arr_lst_rm(num_lst, 0);

    assert(arr_lst_size(num_lst) == 3);
    assert(arr_lst_cap(num_lst) == 10);

    assert(arr_lst_get(num_lst, 0) == b);
    assert(arr_lst_get(num_lst, 1) == c);
    assert(arr_lst_get(num_lst, 2) == d);

    arr_lst_rm(num_lst, 2);
    assert(arr_lst_size(num_lst) == 2);
    assert(arr_lst_cap(num_lst) == 10);

    arr_lst_des(num_lst);

    return 0;
}
