CC=gcc
FLAGS=-O3 -ansi -Wall

all: compile
compile: matcher.c
	$(CC) $(FLAGS) matcher.c -o project

compile-merged: merge merged_project.c
	$(CC) $(FLAGS) merged_project.c -o project

merge: matcher.c dynamic_array.h algorithms/naive_search.h algorithms/Boyer-Moore.h algorithms/KMP.h
	grep -h '#include <' matcher.c dynamic_array.h algorithms/* -d recurse > merged_project.c;
	cat dynamic_array.h algorithms/* matcher.c | grep -v '#include\|#endif\|#ifndef\|define ___' >> merged_project.c;

clean:
	rm project merged_project.c

