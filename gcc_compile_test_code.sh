#!/bin/bash
#
# Compile all the code to test
#
# Last update: 19/06/2023
#
IFSOLD=$IFS

IFS=$(echo -en "\n\b") # Change the Internal Field Separator (IFS) to "\n\b"

stdVersion="c99" # c89 c99 c11 c17 c18

for file in $(ls *.c); do
    echo "gcc -Wall -Wextra -Wpedantic -O3 -std=$stdVersion \"$file\" -o test.out"
    gcc -Wall -Wextra -Wpedantic -O3 -std=$stdVersion "$file" -o test.out

    # or
#     echo "gcc -Wall -Wextra -Wpedantic -O3 -ansi \"$file\" -o test.out"
#     gcc -Wall -Wextra -Wpedantic -O3 -ansi "$file" -o test.out
done

IFS=$IFSOLD
