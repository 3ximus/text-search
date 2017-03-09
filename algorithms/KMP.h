#ifndef ___KMP_SEARCH__H__
#define ___KMP_SEARCH__H__

#include "../dynamic_array.h"

int *compute_pi(char *P, size_t m) {
    int *pi = malloc(m * sizeof(int));
    pi[0]=-1; /* first element is always zero */

    for (int i = 1; i < m; i++) {
        if (P[i] == P[pi[i - 1] + 1]) {
            pi[i] = pi[i - 1] + 1;
        }
        else {
            P[i] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d," , pi[i]);
    }
    printf("\n");
    return pi;
}

void KMP(dynamic_array *_T, dynamic_array *_P) {
    size_t n = _T->used;
    size_t m = _P->used;
    char* T = _T->data;
    char* P = _P->data;

    int *pi = compute_pi(P, m);

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