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
    fprintf(stderr, "GET_CHAR received a character not in the alphabet %c", c);
    exit(1);

}

int GET_INDEX(char c) {
    switch(c) {
        case 'T': return TT;
        case 'C': return CC;
        case 'G': return GG;
        case 'A': return AA;
    }
    fprintf(stderr, "GET_INDEX received a character not in the alphabet %c", c);
    exit(1);
}

/**
 * preprocess P with the righmost position of every char in the alphabet
 */
void preprocess_bad_character_rule(int *L, char *P, int m) {
    int i;
    for (i = 0; i < ALPHABET_SIZE ; i++) L[i] = NON_EXISTENT; /* initialize L */
    for (i = 0; i < m ; i++) L[GET_INDEX(P[i])] = i; /* set last index for each char */
}

/**
 * return value of the proposed shift
 */
int bad_character_rule(char *L, char c, int current_P_index) {
    int new_index = L[GET_INDEX(c)]; /* get rightmost ocurrence of c in P */
    if (new_index < current_P_index) return 1; /* negative shift case (shift only 1 char) */
    else return new_index - current_P_index;
}

int good_sufix_rule() {
    /* TODO */
    return 0;
}

void boyer_moore(dynamic_array *_T, dynamic_array *_P) {
    char *P = _P->data, *T = _T->data;
    int n = _T->used, m = _P->used;
    int count = 0;
    int L[ALPHABET_SIZE];

    preprocess_bad_character_rule(L, P, m);

	int t_it = m -1; /* string T index set to the end of pattern */
    while (t_it < n) {
        int p_it;
        for (p_it = m -1; p_it >= 0; p_it--) {
            if (P[p_it] == T[t_it]) t_it--;
            else break;
        }
        if (p_it == 0 ) printf("%d ", t_it);

        /* TODO perform the shift */
        t_it+=10;
    }

    printf("\n%d \n", count);
}

#endif /* ___BOYER_MOORE_SEARCH__H__ */
