#ifndef ___KMP_SEARCH__H__
#define ___KMP_SEARCH__H__

#include "../dynamic_array.h"

int *compute_pi(char *P, size_t m) {
    int *pi = malloc(m * sizeof(int));
    pi[0]=-1; /* first element is always zero */

    for (int i = 1; i < m; i++) {
        if (P[i] == P[pi[i - 1] + 1]) {
            pi[i] = pi[i - 1] + 1
        }
        else {
            P[i] = -1;
        }
    }
    return pi;
}

void KMP(dynamic_array *T, dynamic_array *P) {
    int *pi = compute_pi(P->data, P->used);


    printf("TODO\n");

}

#endif // ___KMP_SEARCH__H__