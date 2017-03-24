#!/bin/bash

[[ -z $1 || -z $2 || -z $3 ]] && echo "No arguments" && exit 1

testname="${1}.txt"
size="$2"
pattern="$3"

echo -n "T " > tests/$testname
cat /dev/urandom | tr -dc 'ACGT' | head -c $size >> tests/$testname
echo -e "\nN $pattern" >> tests/$testname
echo "K $pattern" >> tests/$testname
echo "B $pattern" >> tests/$testname
echo "X" >> tests/$testname

echo "empty" > tests/expected-output/$testname

echo "generated tests/$testname"
