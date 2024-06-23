#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int sum;
    int x=0;
    for(x =0;x<argc;x++){
        sum+=atoi(argv[x]); /*atoi zwraca 0, jesli argument nie jest liczba, wi>*/
    }

    printf("Suma: %d\n", sum);
    return sum;
}
