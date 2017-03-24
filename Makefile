CC=gcc
FLAGS=-O3 -ansi -Wall

all: compile
compile: matcher.c
	$(CC) $(FLAGS) matcher.c -o project

compile-merged: merge merged_project.c
	$(CC) $(FLAGS) merged_project.c -o project

merge: matcher.c dynamic_array.h algorithms/naive_search.h algorithms/Boyer-Moore.h algorithms/KMP.h
	grep -h '#include <' matcher.c dynamic_array.h algorithms/* -d recurse > merged_project.c;
	grep -h HEADER matcher.c -B40 -m1 > matcher_header.txt;
	grep -h HEADER matcher.c -A200 -m1 > matcher_tail.txt;
	grep -h '#define [^_]\|#if \|#else\|#endif$$' matcher_header.txt dynamic_array.h algorithms/* -d recurse >> merged_project.c;
	cat dynamic_array.h algorithms/* | grep -v '#include\|#endif\|#if\|#define\|#else' >> merged_project.c;
	cat matcher_tail.txt >> merged_project.c;
	rm matcher_header.txt matcher_tail.txt;

clean:
	if [[ -e merged_project.c ]]; then rm merged_project.c; fi;
	if [[ -e project ]]; then rm project; fi;

