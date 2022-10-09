#!/bin/bash
#
# Compile all the code to test
#
# Last update: 09/10/2022
#
set -eEuo pipefail
trap 'echo -e "\\n\\n\e[1;31mError at line $LINENO\033[0m - Command:\\n\e[1;31m$BASH_COMMAND\033[0m\\n"' ERR

IFSOLD=$IFS

IFS=$(echo -en "\\n\\b") # Change the Internal Field Separator (IFS) to "\\n\\b"

stdVersion="c99" # c89 c99 c11 c17 c18

for file in $(ls *.c); do
    echo "gcc -Wall -Wextra -Wpedantic -O3 -std=$stdVersion \"$file\" -o test.out"
    gcc -Wall -Wextra -Wpedantic -O3 -std=$stdVersion "$file" -o test.out

    # or
#     echo "gcc -Wall -Wextra -Wpedantic -O3 -ansi \"$file\" -o test.out"
#     gcc -Wall -Wextra -Wpedantic -O3 -ansi "$file" -o test.out
done

IFS=$IFSOLD
