#!/bin/bash

echo "
#########
COMPILING
#########
"

# compile merged
make compile-merged

#run tests
for in in tests/*.txt; do
	tst="${in##*/}"
	out="tests/${tst}.out"
	echo -en "\t\e[1;38;5;215mRunning $in \e[0m > $out"
	./project < $in > $out
	# FIX BELLOW
	output=$(diff -y $out "tests/expected-output/$tst")
	if [[ $output ]]; then
		echo -e "  [ \e[1;38;5;196mFailed\e[0m ]"
		echo "Test								Expected"
		diff -y $out "tests/expected-output/$tst"
	else
		echo -e "  [ \e[1;38;5;41Succeded\e[0m ]"
	fi

done

# clean
make clean
