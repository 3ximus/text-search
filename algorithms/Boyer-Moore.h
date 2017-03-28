#ifndef ___BOYER_MOORE_SEARCH__H__
#define ___BOYER_MOORE_SEARCH__H__

/* define alphabet */
#define ALPHABET_SIZE 4
#define NON_EXISTENT -1

int GET_INDEX(char c) {
    switch(c) {
        case 'T': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'A': return 3;
    }
    fprintf(stderr, "\nGET_INDEX received a character not in the alphabet %c\n", c);
    exit(1);
}

/**
 * preprocess P into L being this the righmost position in P of every char in the alphabet
 */
void preprocess_bad_character_rule(int *L, char *P, int m) {
    int i;
    for (i = 0; i < ALPHABET_SIZE ; i++) L[i] = NON_EXISTENT; /* initialize L */
    for (i = 0; i < m -1 ; i++) L[GET_INDEX(P[i])] = i; /* set last index for each char */
}

/**
 * return value of the proposed shift
 */
int bad_character_rule(int *L, char c, int P_index) {
    int new_index = L[GET_INDEX(c)]; /* get rightmost ocurrence of c in P */
    return new_index <= P_index ? 1 : new_index - P_index;
}

/**
 * preprocess rightmost suffix into Z table, Z algorithm
 */
void preprocess_good_sufix_rule(int *Z, char* P, int m) {
    int i, suffix_len;
    for (i = 0; i < m; i++) Z[i] = 0; /* initialize Z */
    for (i = 0; i < m ; i++) {
        for (suffix_len = 0; (P[i - suffix_len] == P[m -1 -suffix_len]) && (suffix_len <= i); suffix_len++);
        Z[m - suffix_len] = i; /* since i increments rightmost ocurrence is assured */
    }
}

int good_sufix_rule(int *Z, int P_index) {
    int new_index = Z[P_index+1]; /* mismatch happened at P_index, so the suffix we are after is at P_index +1 */
    return new_index <= P_index ? 1 : new_index - P_index;
}

void boyer_moore(dynamic_array *_T, dynamic_array *_P) {
    char *P = _P->data, *T = _T->data;
    int n = _T->used, m = _P->used;
    int count = 0;
    int L[ALPHABET_SIZE]; /* table for bad character rule */
    int *Z = malloc(sizeof(int) * m); /* table for good sufix rule */

    preprocess_bad_character_rule(L, P, m);
    preprocess_good_sufix_rule(Z, P, m);

	int t_it = m - 1; /* string T index set to the end of pattern */
    while (t_it < n) {
        int p_it = m -1;
        int base_t_it = t_it; /* keep track of pattern position */
        while (p_it >= 0 && P[p_it] == T[t_it]) { /* iterate over pattern/string backwards */
            p_it--;
            t_it--;
            count++;
        }
        if (p_it < 0 ) { /* pattern match */
            printf("%d ", t_it +1);
            t_it = base_t_it + 1; /* shift of 1 */
        } else /* perform the shift */
            t_it = base_t_it + MAX(bad_character_rule(L, T[t_it], p_it), good_sufix_rule(Z, p_it));
    }

    printf("\n%d \n", count);
}

#endif /* ___BOYER_MOORE_SEARCH__H__ */
