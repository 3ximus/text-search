#ifndef ___NAIVE_SEARCH__H__
#define ___NAIVE_SEARCH__H__

#include "../dynamic_array.h"

void naive_online_search(dynamic_array *T, dynamic_array *P) {
    printf("--- Running naive_online_search:\n");

    size_t n = T->used;
    size_t m = P->used;
    for (size_t i = 0; i <= n - m; i++) {
        if(strncmp(T->data+i, P->data, m) == 0) {
            // @See: migth print one space too many for mooshack
            printf("%d ", i);
        }
    }
    printf("\n\n");
}

#endif //___NAIVE_SEARCH__H__
