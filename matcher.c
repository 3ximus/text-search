
#define COUNT_TIME 1
#define DEBUG 0

#if COUNT_TIME
#define _POSIX_C_SOURCE 199309L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "algorithms/naive_search.h"
#include "algorithms/Boyer-Moore.h"
#include "algorithms/KMP.h"

#define INPUT_BUFFER_SIZE 1024
#define NANO_FACTOR 1E9

#if DEBUG
#define LOG_CMD(...) printf(__VA_ARGS__)
#else
#define LOG_CMD(...)
#endif

/* HEADER - dont remove this */

#if COUNT_TIME
#include <time.h>
#define START_COUNTER() start_count()
#define STOP_COUNTER(...) log_time(__VA_ARGS__)

struct timespec startTime, endTime;
FILE* fp;

void start_count() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startTime);
}

/* also stops counter */
void log_time(char* text) {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endTime);
    double dt = endTime.tv_sec - startTime.tv_sec + (endTime.tv_nsec - startTime.tv_nsec) / NANO_FACTOR;
    fprintf(fp, "\t%s - %f seconds\n" , text, dt);
}

#else
#define START_COUNTER()
#define STOP_COUNTER(...)
#endif



int main() {
    dynamic_array T = make_da(512);
    dynamic_array P = make_da(256);

#if COUNT_TIME
    fp = fopen("time.log", "w");
#endif

    int should_quit = 0;

    char c;
    while(!should_quit) {
        if((c = getchar()) == EOF) {
            printf("Reading next command failed. Exiting..");
            break;
        }

        LOG_CMD("Command %c\n", c);
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
                START_COUNTER();
                naive_online_search(&T, &P);
                STOP_COUNTER("N");
                break;

            case 'K':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                START_COUNTER();
                KMP(&T, &P);
                STOP_COUNTER("K");
                break;

            case 'B':
                getchar();
                da_clear(&P);
                da_read_and_insert_until(&P, '\n');
                START_COUNTER();
                boyer_moore(&T, &P);
                STOP_COUNTER("B");
                break;

            default:
                printf("Unknown command %c", c);
                exit(-1);
        }
    }

    da_free(&T);
    da_free(&P);

#if COUNT_TIME
    fclose(fp);
#endif

    return 0;
}