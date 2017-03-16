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

int GET_INT(char c) {
    switch(c) {
        case 'T': return TT;
        case 'C': return CC;
        case 'G': return GG;
        case 'A': return AA;
    }
}

/* bad character rule */

int *preprocess_bad_character_rule(dynamic_array *_P) {
    static int L[ALPHABET_SIZE] = { -1, -1, -1, -1};
    char* P = _P->data;
    int counter = 0, chr_index;
    for (int i = _P->size -1 ; i >= 0; i--) {
        chr_index = GET_INT(P[i]);
        if (L[chr_index] == -1) {
            L[chr_index] = i;
            counter++;
        }
        if (counter == 4) break;
    }
    return L;
}

int bad_character_rule(char *P, char* T, int current_index) {
    /* TODO */
}

int good_sufix_rule() {
    /* TODO */
}

void boyer_moore(dynamic_array *T, dynamic_array *P) {
    int *L = preprocess_bad_character_rule(_P);

    printf("TODO\n");
    printf("TODO\n");
}

#endif // ___BOYER_MOORE_SEARCH__H__
