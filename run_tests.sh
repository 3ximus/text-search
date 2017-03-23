#!/bin/bash

echo "
#########
COMPILING
#########
"
if ! make compile-merged ; then
    exit 1;
fi

hash colordiff 2>/dev/null && DIFF=colordiff || DIFF=diff

for in in tests/*.txt; do
	tst="${in##*/}"
	out="tests/${tst}.out"
	echo -en "\t\e[1;38;5;215mRunning $in \e[0m > $out"
	{ time ./project <$in >$out ; } 2>${out}.time
	output=$(diff -q $out "tests/expected-output/$tst")
	if [[ $output ]]; then
		echo -e "  [ \e[1;38;5;196mFailed\e[0m ]"
		echo "Test								Expected"
		$DIFF -y $out "tests/expected-output/$tst"
	else
		echo -en "  [ \e[1;38;5;41mSucceded\e[0m ]"
		grep "real" ${out}.time | sed 's/real/  time/'
	fi

done
make clean
