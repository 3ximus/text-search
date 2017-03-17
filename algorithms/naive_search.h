#ifndef ___NAIVE_SEARCH__H__
#define ___NAIVE_SEARCH__H__

void naive_online_search(dynamic_array *T, dynamic_array *P) {
    /* printf("--- Running naive_online_search:\n"); */

    int n = T->used;
    int m = P->used;
    int i;
    for (i = 0; i <= n - m; i++) {
        if(strncmp(T->data+i, P->data, m) == 0) {
            /* @See: migth print one space too many for mooshack */
            printf("%d ", i);
        }
    }
    printf("\n");
}

#endif /*___NAIVE_SEARCH__H__ */
