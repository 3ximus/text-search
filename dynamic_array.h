#ifndef ___DYNAMIC_ARRAY__H__
#define ___DYNAMIC_ARRAY__H__

#include <assert.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct da_struct {
    int initial_size;

    char *data;
    int used;
    int size;
} dynamic_array;

dynamic_array make_da(int initial_size) {
    dynamic_array da;
    da.initial_size = MAX(8, initial_size);
    da.size = initial_size;
    da.used = 0;
    da.data = realloc(NULL, initial_size);

    /*
    printf("Allocating initial size to %d\n", da.size);
    */

    return da;
}

void da_resize(dynamic_array *da, int new_size) {
    assert(da);

    if (new_size == da->size) return;

    da->size = new_size;
    da->data = realloc(da->data, new_size);
    /*
    printf("Reallocating to size %d\n", da->size);
    */
}

void da_insert(dynamic_array *da, char c) {
    assert(da);

    if (da->used == da->size) {
        int new_size = da->size*2;
        da_resize(da, new_size);
    }
    da->data[da->used++] = c;
}
/*
void da_delete_at(dynamic_array *da, int i) {
    if(i < 0 || i >= da->used) {
        printf("Invalid delete: index smaller or larger than the array size!\n");
        return;
    }

    da->used--;
    da->data[i] = da->data[da->used];

    if(da->size > da->initial_size && da->used <= da->size / 4) {
        da_resize(da, da->size / 2);
    }
}
*/

void da_free(dynamic_array *da) {
    assert(da);

    if(da->data) {
        free(da->data);
        da->data = NULL;
        da->used = 0;
        da->size = 0;
    }
}

void da_print(dynamic_array *da) {
    assert(da);

    printf("************************\n");
    printf("used      : %d\n", da->used);
    printf("size_size: %d\n", da->size);
    printf("data: ");

    int i;
    for(i = 0; i < da->used; i++) {
        printf("%c", da->data[i]);
    }

    printf("\n");
    printf("************************\n");
}

int da_empty(dynamic_array *da) {
    assert(da);

    return da->used;
}

void da_clear(dynamic_array *da) {
    assert(da);

    da->used = 0;
    da_resize(da, da->initial_size);
}

void da_read_and_insert_until(dynamic_array *da, char delimiter) {
    assert(da);

    char c;
    while ((c = getchar()) != delimiter && c != EOF) {
        da_insert(da, c);
    }
}

#endif /* ___DYNAMIC_ARRAY__H__ */
