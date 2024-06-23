#!/bin/bash

config_file="config.cfg"


if [ -f "$config_file" ]; then
    echo "Wykonywanie pliku $config_file"
    ./config.cfg

elif [ $# -eq 1 ]; then
    custom_file="$1"
    if [ -f "$custom_file" ]; then
        echo "Wykonywanie pliku $custom_file"
        ./$custom_file
    else
        echo "Błąd: Plik $custom_file nie istnieje."
    fi
else
    echo "Błąd: Brak pliku config.cfg oraz nie podano żadnego argumentu."
fi
