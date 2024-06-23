#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Nie podano żadnych plików."
    exit 1
fi

echo "Zawartość plików od początku do końca:"
for file in "$@"; do
    echo "Zawartość pliku $file:"
    while IFS= read -r line; do
        echo "$line"
    done < "$file"
    echo ""
done

echo "Zawartość plików od końca do początku:"
for file in "$@"; do
    lines=$(wc -l < "$file")
    for (( i=lines; i>=1; i-- )); do
        sed "${i}q;d" "$file"
    done
    echo ""
done

