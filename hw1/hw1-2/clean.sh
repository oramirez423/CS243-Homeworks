#!/bin/bash
#Omar Ramirez-Chio

if [ $# -lt 2 ]; then
	echo "Incorrect number of arguments"
	exit 1
fi

rm $1.o
rm $1

