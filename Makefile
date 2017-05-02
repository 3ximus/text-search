CC=gcc
FLAGS=-O3 -ansi -Wall -g

all: compile
compile: matcher.c
	$(CC) $(FLAGS) matcher.c -o project

compile-merged: merge merged_project.c
	$(CC) $(FLAGS) merged_project.c -o project

merge: matcher.c dynamic_array.h algorithms/naive_search.h algorithms/Boyer-Moore.h algorithms/KMP.h
	grep HEADER matcher.c -B100 | grep -v '#include \"' > merged_project.c
	cat dynamic_array.h algorithms/*.h | grep -v '#include \"\|#endif /\*\|#ifndef ___\|#define ___' >> merged_project.c;
	grep HEADER matcher.c -A300 >> merged_project.c

clean:
	if [[ -e merged_project.c ]]; then rm merged_project.c; fi;
	if [[ -e project ]]; then rm project; fi;

