#ifndef ___BOYER_MOORE_SEARCH__H__
#define ___BOYER_MOORE_SEARCH__H__

/* define alphabet */

#define ALPHABET_SIZE 4
#define TT 0
#define CC 1
#define GG 2
#define AA 3

char GET_CHAR(int c) {
    switch(c) {
        case TT: return 'T';
        case CC: return 'C';
        case GG: return 'G';
        case AA: return 'A';
    }
}

int GET_INDEX(char c) {
    switch(c) {
        case 'T': return TT;
        case 'C': return CC;
        case 'G': return GG;
        case 'A': return AA;
    }
}

/**
 * preprocess P with the righmost position of every char in the alphabet
 */
int *preprocess_bad_character_rule(char *P, size_t size) {
    static int L[ALPHABET_SIZE] = { -1, -1, -1, -1};
    int counter = 0, chr_index;
    for (int i = size -1 ; i >= 0; i--) {
        chr_index = GET_INDEX(P[i]);
        if (L[chr_index] == -1) {
            L[chr_index] = i;
            counter++;
        }
        if (counter == ALPHABET_SIZE) break;
    }
    return L;
}

/**
 * return value of the proposed shift
 */
int bad_character_rule(char *L, char c, int current_P_index) {
	/* get rightmost ocurrence of c in P */
    int new_index = L[GET_INDEX(c)];
    if (new_index < current_P_index) return 1; /* negative shift case (shift only 1 char) */
    else return new_index - current_P_index;
}

int good_sufix_rule() {
    /* TODO */
}

void boyer_moore(dynamic_array *T, dynamic_array *P) {
    int *L = preprocess_bad_character_rule(P->data, P->size);

    printf("TODO\n");
    printf("TODO\n");
}

#endif // ___BOYER_MOORE_SEARCH__H__
