#ifndef ___KMP_SEARCH__H__
#define ___KMP_SEARCH__H__

int *compute_pi(char *P, int m) {
    int *pi = malloc(m * sizeof(int));
    pi[0] = -1; /* first element is always zero */

    for (int i = 1; i < m; i++) {
        if (P[i] == P[pi[i - 1] + 1]) {
            pi[i] = pi[i - 1] + 1;
        }
        else {
            pi[i] = -1;
        }
    }
    /* TODO REMOVE IN THE FUTURE
    for (int i = 0; i < m; i++) {
        printf("%d," , pi[i]);
    }
    printf("\n");
    */
    return pi;
}

// '\0' at the the end of P counts for the count
void KMP(dynamic_array *_T, dynamic_array *_P) {
    int n = _T->used;
    int m = _P->used;
    char* T = _T->data;
    char* P = _P->data;
    int count = 0;

    int *pi = compute_pi(P, m);

    int q = -1;
    for(int i = 0; i < n; i++) {
        while(q > -1) {
            count++;
            if (P[q + 1] != T[i]) {
                q = pi[q];
            } else {
                q++;
                break;
            }
        }

        // We can skip the comparison because we've checked before above
        if (q == -1) {
            count++;
            if(P[q + 1] == T[i])
                q++;
        }

        // We have found a match
        if(q == m - 1) {
            printf("%d ", i - m + 1);
            if(i != n-1) count++;
            q = pi[q];
        }
    }

    free(pi);
    printf("\n%d \n", count);
}

#endif // ___KMP_SEARCH__H__
