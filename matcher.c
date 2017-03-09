#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "algorithms/naive_search.h"
#include "algorithms/Boyer-Moore.h"
#include "algorithms/KMP.h"

#define DEBUG 1
#define INPUT_BUFFER_SIZE 1024

int main() {
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
                KMP(&T, &P);
                break;

            case 'B':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                boyer_moore(&T, &P);
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