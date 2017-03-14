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

void KMP(dynamic_array *_T, dynamic_array *_P) {
    int n = _T->used;
    int m = _P->used;
    char* T = _T->data;
    char* P = _P->data;
    int count = 0;

    int *pi = compute_pi(P, m);

    int q = -1;
    for(int i = 0; i < n; i++) {
        while(q > -1 ) {
            if (P[q + 1] != T[i]) {
                q = pi[q];
            }
            printf("-- %d %d\n", q, i);
            count++;
            break;
        }
        printf("** %d %d\n", q, i);

        count++;
        if (P[q + 1] == T[i]) {
            q++;
        }

        if(q == m - 1) {
            //printf("%d ", i - m + 1);
            q = pi[q];
        }
    }
    free(pi);
    printf("\n%d \n", count + m);
}

#endif // ___KMP_SEARCH__H__
