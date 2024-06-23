#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int x=0;
    int y=0;
    int height=0;


    if(argc<2){
        perror("Not enough arguments were passed!\n");
        return 1;
    }

    height = atoi(argv[1]);

    printf("\n");
    for(x=1;x<=height;x++){

        for(y=height-x;y>=0;y--)/*print spaces to put our tree in the middle*/
            printf(" ");

        for(y=0;y<x*2-1;y++)
            printf("*");
        printf("\n");

    }
    return 0;
}
