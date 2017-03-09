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
    size_t n = T->used;
    size_t m = P->used;

    int *pi = compute_pi(P->data, m);

    size_t q = -1;
    for(size_t i = 0; i < n; i++) {
        while(q > -1 && P[q+1] != T[i]) {
            q = pi[q];
        }

        if(P[q+1] == T[i]) {
            q++;
        }

        if(q == m - 1) {
            printf("%d\n", i-m);
            q = pi[q];
        }
    }
    free(pi);
}

#endif // ___KMP_SEARCH__H__