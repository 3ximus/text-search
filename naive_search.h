void naive_online_search(dynamic_array *T, dynamic_array *P) {
    printf("--- Running naive_online_search:\n");

    size_t T_size = T->used;
    size_t P_size = P->used;
    for (size_t i = 0; i < T_size - P_size + 1; i++) {
        if(strncmp(T->data+i, P->data ,P_size) == 0) {
            // @See: migth print one space too many for mooshack
            printf("%d ", i);
        }
    }
    printf("\n\n");
}