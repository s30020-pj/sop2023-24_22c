#!/bin/bash

IFS=$'\n'

for item in $(ls); do
    echo "Patrzcie Państwo, oto plik: $item"
done

