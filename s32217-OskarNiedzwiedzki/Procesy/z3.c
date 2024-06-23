#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#define _ERROR_NOT_ENOUGH_ARGUMENTS 1
#define _ERROR_PROCESS 2

void do_child_work(int arg);
void do_parent_work(int arg);

int main(int argc, char** argv){
    pid_t child;
    int num=0;

    if(argc < 2){
       printf("Not enough arguments were passed!\n");
       return _ERROR_NOT_ENOUGH_ARGUMENTS;
    }

    child = fork();
    num = atoi(argv[1]);
    if(child < 0){
	    printf("Error - process could not be created!\n");
	    return _ERROR_PROCESS;
    }
    else if(child==0){
	do_child_work(num);
	return EXIT_SUCCESS;
    }
    else{
	waitpid(child,NULL,0);
	do_parent_work(num);
	return EXIT_SUCCESS;
    }
}


void do_child_work(int arg){
   int iter = 1;
   printf("\nChild is working...\n");
   while(iter<=arg){
	  printf("%d\n", iter);
	  iter+=2;
   }
}

void do_parent_work(int arg){
    int iter=1;
    printf("\nParent is working...\n");
    for(iter=1;iter<=arg;iter++)
	    printf("%d\n", iter);

}


