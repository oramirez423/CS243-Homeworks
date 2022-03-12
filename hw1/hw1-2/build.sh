#!/bin/bash
#Omar Ramirez-Chio

if [ $# -eq 0 ];
then
	echo "Incorrect number of arguments"
	exit 1
fi

gcc -std=c99 -Wall -Wextra -pedantic -ggdb -c $1.c
gcc -std=c99 -Wall -Wextra -pedantic -ggdb $1.c -o -$1
gcc $1.c -o program -lm
