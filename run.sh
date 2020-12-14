#!/bin/bash
FILE=a.exe
if test -f "$FILE"; then
    echo "$FILE removed!"
    rm $FILE
fi
PROG_NAME=$1
echo $PROG_NAME
output=$(g++ -Wall -Wextra -Werror -Wpedantic -Wunused -std=c++17 $PROG_NAME)  #redirect the error to a variable
echo $output              #show the error on stdout
if test -f "$FILE"; then
    echo "$FILE output:"
    ./$FILE
fi