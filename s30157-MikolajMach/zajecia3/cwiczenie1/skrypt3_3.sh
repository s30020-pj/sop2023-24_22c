#!/bin/bash

if [ "${0: -3}" != ".sh" ]; then
    new_name="${0}.sh"
    mv "$0" "$new_name"
    echo "Zmieniono nazwę skryptu na: $new_name"
    exit
fi

echo "Nazwa skryptu jest już poprawna."
