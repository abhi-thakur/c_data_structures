#include "list/array_list.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define equal_strs(s1, s2) strcmp(s1, s2) == 0

void test_array_list();

int main(int argc, char** argv) {
    test_array_list();
    printf("All test passed !\n");
}

int num_cmp(void* f, void* s) {
    return (int) f == (int) s;
}

void test_array_list() {
    int size = 100000;

    array_list* numbers = arr_lst_new(sizeof(int));

    assert(arr_lst_size(numbers) == 0);
    assert(arr_lst_cap(numbers) == 10);

    // [#1 Testing add operation] - START
    for (int i = 0; i < size; i++) {
        arr_lst_add(numbers, (void*) i);
    }

    assert(arr_lst_size(numbers) == size);
    // [#1 Testing add operation] - END

    
    // [#2 Testing get operation] - START
    assert(arr_lst_get(numbers, 53) == (void*)53);
    assert(arr_lst_get(numbers, 54) == (void*)54);
    assert(arr_lst_get(numbers, 55) == (void*)55);
    // [#2 Testing get operation] - END

    // [#3 Testing set operation] - START
    arr_lst_set(numbers, 1111, (void*)1001);
    assert(arr_lst_get(numbers, 1111) == (void*)1001);
    assert(arr_lst_get(numbers, 1112) == (void*)1112);

    arr_lst_set(numbers, 1111, (void*)1111);
    assert(arr_lst_get(numbers, 1111) == (void*)1111);
    assert(arr_lst_get(numbers, 1112) == (void*)1112);
    // [#3 Testing set operation] - END

    // [#4 Testing pop operation] - START
    arr_lst_pop(numbers);
    arr_lst_pop(numbers);
    arr_lst_pop(numbers);
    assert(arr_lst_pop(numbers) == (void*)(size - 4));
    assert(arr_lst_pop(numbers) == (void*)(size - 5));

    assert(arr_lst_size(numbers) == size - 5);
    // [#4 Testing pop operation] - END

    // [#5 Testing insert operation] - START
    int old_size = arr_lst_size(numbers);

    arr_lst_insert(numbers, 0, (void*)-1);
    arr_lst_insert(numbers, 1, (void*)0);
    arr_lst_insert(numbers, 79999, (void*)79999);

    assert(arr_lst_get(numbers, 0) == (void*)-1);
    assert(arr_lst_get(numbers, 1) == (void*)0);
    assert(arr_lst_get(numbers, 79999) == (void*)79999);
    assert(arr_lst_get(numbers, 80000) != (void*)80000);

    assert(arr_lst_size(numbers) == old_size + 3);
    // [#5 Testing insert operation] - END

    // [#6 Testing remove operation] - START
    old_size = arr_lst_size(numbers);
    arr_lst_rm(numbers, 0);
    arr_lst_rm(numbers, 1);
    arr_lst_rm(numbers, 79999);

    assert(arr_lst_size(numbers) == old_size - 3);
    assert(arr_lst_get(numbers, 0) == (void*)0);
    assert(arr_lst_get(numbers, 1) == (void*)1);
    assert(arr_lst_get(numbers, 79999) == (void*)79999);
    assert(arr_lst_get(numbers, 80000) == (void*)80000);
    // [#6 Testing remove operation] - END

    // [#7 Testing index of operation] - START
    assert(arr_lst_indexof(numbers, (void*)0, &num_cmp) == 0);
    assert(arr_lst_indexof(numbers, (void*)1, &num_cmp) == 1);
    assert(arr_lst_indexof(numbers, (void*)78552, &num_cmp) == 78552);
    assert(arr_lst_indexof(numbers, (void*)90000, &num_cmp) == 90000);
    // [#7 Testing index of operation] - END

    // [#8 Testing clear operation] - START
    short ini_cap = 10;
    assert(arr_lst_size(numbers) != 0);
    assert(arr_lst_cap(numbers) != ini_cap);

    arr_lst_clr(numbers);
    assert(arr_lst_size(numbers) == 0);
    assert(arr_lst_cap(numbers) == ini_cap);
    // [#8 Testing clear operation] - END
}
