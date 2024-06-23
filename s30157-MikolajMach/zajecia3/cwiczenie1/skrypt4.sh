#!/bin/bash

file_count=$(find . -maxdepth 1 -type f | wc -l)

if [ "$file_count" -gt 5 ]; then
    echo "W bieżącym katalogu jest więcej niż 5 plików."
elif [ "$file_count" -eq 5 ]; then
    echo "W bieżącym katalogu jest dokładnie 5 plików."
else
    echo "W bieżącym katalogu jest mniej niż 5 plików."
fi
