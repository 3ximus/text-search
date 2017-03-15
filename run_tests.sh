#!/bin/bash

# compile merged
echo "
#########
COMPILING
#########
"

make compile-merged

#run tests
for in in tests/*.txt; do
	tst="${in##*/}"
	out="tests/${tst}.out"
	echo -e "\t\e[1;38;5;215mRunning $in \e[0m > $out"
	./project < $in > $out
	# FIX BELLOW
	echo "Test								Expected"
	diff -y $out "tests/expected-output/$tst"
done

# clean
make clean
