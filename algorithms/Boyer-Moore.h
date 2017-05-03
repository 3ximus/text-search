#ifndef ___BOYER_MOORE_SEARCH__H__
#define ___BOYER_MOORE_SEARCH__H__

/* define alphabet */
#define ALPHABET_SIZE 4

#define MAX(a,b) (((a)>(b))?(a):(b))

int GET_INDEX(char c) {
	switch(c) {
		case 'T': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'A': return 3;
	}
	fprintf(stderr, "\n\e[31mGET_INDEX received a character not in the alphabet %x\e[0m\n\n", c);
	exit(1);
}

/**
 * preprocess P into L being this the righmost position in P of every char in the alphabet
 */
void preprocess_bad_character(int *L, char *P, int m) {
	int i;
	for (i = 0; i < ALPHABET_SIZE ; i++) L[i] = m; /* initialize L */
	for (i = 0; i < m - 1 ; i++) L[GET_INDEX(P[i])] = m - i - 1; /* set last index for each char */
}

/**
 * create sufix table containing the largest suffixes of the pattern contained in itself
 */
void compute_suffixes(char *P, int m, int *suffixes) {
	int f = 0, g, i;

	suffixes[m-1] = m;
	g = m -1;
	for (i = m -2; i >= 0; i--) {
		if (i > g && suffixes[i + m - 1 - f] < i - g) suffixes[i] = suffixes[i + m -1 - f];
		else {
			if (i < g) g = i;
			f = i;
			while (g >= 0 && P[g] == P[g + m - 1 - f]) g--; /* compare with suffix until mismatch */
			suffixes[i] = f - g; /* store length of suffix */
		}
	}
}

/**
 * preprocess rightmost suffix into Z table, Z algorithm
 */
void preprocess_good_suffix(int *Z, char* P, int m) {
	int i, j = 0, *suffixes = malloc(sizeof(int) * m);
	compute_suffixes(P, m, suffixes);

	for (i = 0; i < m; i++)
		Z[i] = m; /* initialize Z */

	for (i = m - 1; i >= 0 ; i--)
		if (suffixes[i] == i + 1)
			for (;j < m - 1 - i; j++)
				if (Z[j] == m)
					Z[j] = m - 1 - i;
	for (i = 0; i <= m - 2; i++)
		Z[m - 1 - suffixes[i]] = m - 1 - i;
}

void boyer_moore(dynamic_array *_T, dynamic_array *_P) {
	char *P = _P->data, *T = _T->data;
	int n = _T->used, m = _P->used;

	int L[ALPHABET_SIZE]; /* table for bad character rule */
	int *Z = malloc(sizeof(int) * m); /* table for good suffix rule */

	int count = 0, j = 0, i;

	/* preprocess tables */
	preprocess_bad_character(L, P, m);
	preprocess_good_suffix(Z, P, m);

	while (j <= n - m) {
		for (i = m -1; i >= 0 && P[i] == T[i + j]; i-- , count++);
		if (i < 0) {
			printf("%d ", j);
			j += Z[0];
		} else j += MAX(Z[i] , L[GET_INDEX(T[i + j])] - m + 1 + i);
	}
	printf("\n%d \n", count);
}

#endif /* ___BOYER_MOORE_SEARCH__H__ */
