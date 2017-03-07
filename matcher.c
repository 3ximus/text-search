#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

#define DEBUG 1
#define INPUT_BUFFER_SIZE 1024

void naive_online_search(dynamic_array *T, dynamic_array *P);

int main() {
    // @Robustness: handle bigger inputs (probably store the pattern in a dynamic array?)
    dynamic_array T = make_da(512);
    dynamic_array P = make_da(256);

    int should_quit = 0;

    char c;
    while(!should_quit) {
        if((c = getchar()) == EOF) {
            printf("Reading next command failed. Exiting..");
            break;
        }
        if(DEBUG) printf("Command %c\n", c);
        switch(c) {
            case 'X':
                should_quit = 1;
                break;
            case 'T':
                getchar();
                da_read_and_insert_until(&T, '\n');
                break;

            case 'N':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                naive_online_search(&T, &P);
                break;

            case 'K':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                break;

            case 'B':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                break;

            default:
                printf("Unknown command %c", c);
                exit(-1);
        }
    }

    da_free(&T);
    da_free(&P);

    return 0;
}

void print_n_chars(char *s, int n) {
    for(int i = 0; i < n; i++) {
        printf("%c", s[i]);
    }
    puts("\n");
}

void naive_online_search(dynamic_array *T, dynamic_array *P) {
    printf("Running naive_online_search\n");

    size_t T_size = T->used;
    size_t P_size = P->used;
    // @See: check off one
    for (size_t i = 0; i < T_size - P_size; i++) {
        // printf("Checking: \n");
        // print_n_chars(T->data+i, P_size);
        // print_n_chars(P->data, P_size);
        if(strncmp(T->data+i, P->data ,P_size) == 0) {
            // @See: migth print one space too many
            printf("%d ", i);
        }
    }
    printf("\n");
}