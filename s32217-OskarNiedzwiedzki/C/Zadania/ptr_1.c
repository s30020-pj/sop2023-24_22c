#include <stdio.h>
#include <stdlib.h>
#define _ERROR_NOT_ENOUGH_ARGUMENTS 1
#define _ERROR_WRONG_INPUT 2
#define _ERROR_MEMORY 3

#define FUNCTION_MIN 0
#define FUNCTION_MAX 1
#define FUNCTION_SUM 2

typedef int(*function)(int,int);

int minimum(int a, int b){
    return a<b ? a : b;
}
int maksimum(int a, int b){
    return a>b ? a : b;
}
int sum(int a, int b){
    return a+b;
}

int forAll(int* tab, int count,function predicate){
    int iter=0;
    int out = 0;
    if(count <=0)
        return 0;

    out =tab[0];
    for(iter=1;iter<count;iter++)
        out = predicate(out,tab[iter]);

    return out;
}


int main(int argc, char** argv){
    function functions[3] = {minimum, maksimum, sum};
    int* vals = NULL;
    int function_id=0;
    int elem_count=0;
    int iter=0;

    if(argc < 3){
        perror("Not enough arguments were passed!\n");
        return _ERROR_NOT_ENOUGH_ARGUMENTS;
    }

    function_id = atoi(argv[1]);
    elem_count = atoi(argv[2]);

    if(function_id < 0 || function_id > 2){
        fprintf(stderr,"Function with id: %d Does not exist!",function_id);
        return _ERROR_WRONG_INPUT;
    }
    if(elem_count <= 0){
        perror("Element count cannot be negative or zero!");
        return _ERROR_WRONG_INPUT;
    }
    if(elem_count != argc - 3){
        perror("Wrong element count!");
        return _ERROR_WRONG_INPUT;
    }

    vals = malloc(sizeof(int)* elem_count);
    if(vals==NULL)
        return _ERROR_MEMORY;

    /*we start from 4, because first 2 indexes are function_id and elem count and 1 element has been loaded*/
    for(iter=3;iter<elem_count+3;iter++)
        vals[iter-3] = atoi(argv[iter]);

    switch (function_id)
    {
        case FUNCTION_MIN:
            printf("\nMin, Output value: %d\n", forAll(vals,elem_count,functions[FUNCTION_MIN]));
            break;
        case FUNCTION_MAX:
            printf("\nMax, Output value: %d\n", forAll(vals,elem_count,functions[FUNCTION_MAX]));
            break;
        case FUNCTION_SUM:
            printf("\nSum, Output value: %d\n", forAll(vals, elem_count, functions[FUNCTION_SUM]));
            break;
        default:
            perror("Undefined function!");
            return _ERROR_WRONG_INPUT;
    }


    return 0;
}


