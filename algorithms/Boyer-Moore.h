#ifndef ___BOYER_MOORE_SEARCH__H__
#define ___BOYER_MOORE_SEARCH__H__

/* define alphabet */

#define ALPHABET_SIZE 4
#define TT 0
#define CC 1
#define GG 2
#define AA 3
#define NON_EXISTENT -1

char GET_CHAR(int c) {
    switch(c) {
        case TT: return 'T';
        case CC: return 'C';
        case GG: return 'G';
        case AA: return 'A';
    }
    fprintf(stderr, "\nGET_CHAR received a character not in the alphabet %c\n", c);
    exit(1);

}

int GET_INDEX(char c) {
    switch(c) {
        case 'T': return TT;
        case 'C': return CC;
        case 'G': return GG;
        case 'A': return AA;
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
    for (i = 0; i < m ; i++) L[GET_INDEX(P[i])] = i; /* set last index for each char */
}

/**
 * return value of the proposed shift
 */
int bad_character_rule(int *L, char c, int current_P_index) {
    int new_index = L[GET_INDEX(c)]; /* get rightmost ocurrence of c in P */
    /* @SEE: Maybe just return the subtraction, and then when deciding use max(bad_char, good_suff, 1) */
    if (new_index < current_P_index) return 1; /* negative shift case (shift 1 char) */
    else return new_index - current_P_index;
}

/**
 * preprocess rightmost suffix into H table, Z algorithm
 */
void preprocess_good_sufix_rule(int *H, char* P) {

}

int good_sufix_rule() {
    /* TODO */
    return 1;
}

void boyer_moore(dynamic_array *_T, dynamic_array *_P) {
    char *P = _P->data, *T = _T->data;
    int n = _T->used, m = _P->used;
    int count = 0;
    int L[ALPHABET_SIZE]; /* table for bad character rule */
    int *H = malloc(sizeof(int) * m); /* table for good sufix rule */

    preprocess_bad_character_rule(L, P, m);
    preprocess_good_sufix_rule(H, P);

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
            t_it = base_t_it + MAX(bad_character_rule(L, T[t_it], p_it), good_sufix_rule());
    }

    printf("\n%d \n", count);
}

#endif /* ___BOYER_MOORE_SEARCH__H__ */
