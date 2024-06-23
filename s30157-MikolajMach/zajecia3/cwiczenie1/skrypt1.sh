#!/bin/bash

# Sprawdzenie czy podano więcej niż jeden parametr
if [ $# -gt 1 ]; then
    echo "Pierwszy parametr: $1"
elif [ $# -eq 1 ]; then
    echo "Tylko jeden parametr został podany: $1"
else
    echo "Nie podano żadnych parametrów."
fi
