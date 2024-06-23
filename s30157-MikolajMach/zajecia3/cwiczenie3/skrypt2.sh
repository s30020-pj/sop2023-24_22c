#!/bin/bash

fibonacci() {
    local n="$1"

    if ((n <= 1)); then
        echo "$n"
        return
    fi

    local fib1=$(fibonacci $((n - 1)))
    local fib2=$(fibonacci $((n - 2)))
    echo $((fib1 + fib2))
}
echo "Podaj n: "
read n

result=$(fibonacci $n)
echo "Wynik: $result"
