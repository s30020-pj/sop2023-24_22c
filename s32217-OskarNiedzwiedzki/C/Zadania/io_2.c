#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <limits.h>
#define _CODE_FILE_NOT_EXIST 1
#define _CODE_MEMORY_ERROR 2

#define BYTE_GROUP 0x10
typedef unsigned char BYTE;

int main(int argc, char** argv){
    /*DECL VARIABLES*/
    FILE* f =       NULL;
    BYTE* block  =  malloc(sizeof(BYTE) * BYTE_GROUP);
    int block_count=0;
    /*END DECL VARIABLES*/

    if(argc<2){
        perror("Not enough arguments were passed!\n");
        return 1;
    }

    if(block==NULL)
        return _CODE_MEMORY_ERROR;

    f = fopen(argv[1], "rb");
    if(f==NULL){
        perror("File does not exist!\n");
        return _CODE_FILE_NOT_EXIST;
    }

    printf("Loaded file: %s\n", argv[1]);

    while(!feof(f)){
        int x=0;
        printf("%08x\t", block_count++);

        /*clear block before reading*/
        memset(block, 0, sizeof(BYTE)* BYTE_GROUP);
        fread(block,sizeof(BYTE),BYTE_GROUP,f);

        for(;x<BYTE_GROUP;x++)
            printf("%02x ", block[x]);

        for(x=0;x<BYTE_GROUP;x++){
            if(!isprint(block[x]))/*Character is not printable*/
                printf("%c", ' ');
            else
                printf("%c", block[x]);
        }

        printf("\n");
    }

    printf("Closing file: %s\n\n", argv[1]);

    /*CLEAR MEMORY*/
    fclose(f);
    free(block);
    /*END CLEAR MEMORY*/

    return 0;
}
