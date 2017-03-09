#ifndef ___KMP_SEARCH__H__
#define ___KMP_SEARCH__H__

#include "../dynamic_array.h"

int *compute_pi(char *P, size_t m) {
    int *pi = malloc(m * sizeof(int));

    for(int i = 0; i < m; i++) {

    }
    return pi;
}

void KMP(dynamic_array *T, dynamic_array *P) {
    int *pi = compute_pi(P->data, P->used);


    printf("TODO\n");

}

#endif // ___KMP_SEARCH__H__