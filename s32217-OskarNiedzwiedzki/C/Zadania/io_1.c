#include <stdio.h>
#include <stdlib.h>
#define _CODE_FILE_NOT_EXIST 1
#define _CODE_MEMORY_ERROR 2

int main(int argc, char** argv){
    /*DECL VARIABLES*/
    int x = 0;
    int num_count=0;
    int* numbers = NULL;
    FILE* f = NULL;
    /*END DECL VARIABLES*/

    if(argc<2){
        printf("Not enough arguments were passed!\n");
        return 1;
    }

    f = fopen(argv[1], "r");
    if(f==NULL){
        printf("File does not exist!\n");
        return _CODE_FILE_NOT_EXIST;
    }

    /*Read first line and get nubmer count*/
    fscanf(f, "%d\n", &num_count);

    numbers = malloc(sizeof(int) * num_count);
    if(numbers==NULL)
        return _CODE_MEMORY_ERROR;

    for(;x<num_count;x++)
        fscanf(f, "%d\n", &numbers[x]);

    printf("Print backwards: \n");
    for(x=num_count-1;x>=0;x--)
        printf("%d\n", numbers[x]);

    /*free memory*/
    free(numbers);
    fclose(f);
    return 0;
}
