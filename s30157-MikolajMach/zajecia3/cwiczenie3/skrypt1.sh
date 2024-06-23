#!/bin/bash

# Funkcja do wypisywania tekstu w wybranym kolorze
print_color_text() {
    local text="$1"
    local color="$2"

    case "$color" in
        "red")
            echo -e "\033[0;31m$text\033[0m"
            ;;
        "green")
            echo -e "\033[0;32m$text\033[0m"
            ;;
        "yellow")
            echo -e "\033[0;33m$text\033[0m"
            ;;
        "blue")
            echo -e "\033[0;34m$text\033[0m"
            ;;
        "violet")
            echo -e "\033[0;35m$text\033[0m"
            ;;
        *)
            echo "Nieobsługiwany kolor: $color"
            ;;
    esac
}
echo "podaj tekst do wyswietlenia: "
read input_text

echo "podaj kolor tekstu: "
read input_color

print_color_text "$input_text" "$input_color"
