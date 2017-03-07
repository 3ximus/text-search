#ifndef ____DYNAMIC_ARRAY___H__
#define ____DYNAMIC_ARRAY___H__

typedef struct dynamic_array {
    size_t initial_size;

    char *data;
    size_t used;
    size_t size;
} dynamic_array;

dynamic_array make_da(size_t initial_size);
void da_resize(dynamic_array *da, int new_size);
void da_insert(dynamic_array *da, char c);
void da_read_and_insert_until(dynamic_array *da, char delimiter);
void da_delete_at(dynamic_array *da, int i);
void da_free(dynamic_array *da);
void da_print(dynamic_array *da);
int  da_empty(dynamic_array *da);
void da_clear(dynamic_array *da);

#endif //____DYNAMIC_ARRAY___H__