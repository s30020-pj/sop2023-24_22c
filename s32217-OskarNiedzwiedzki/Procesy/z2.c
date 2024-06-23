#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> /*pid_t*/
#define _ERROR_PROCESS 1

int main(int argc, char** argv){
    pid_t p;

    p = fork();
    if(p<0){
	printf("Process could not be created!\n");
	return _ERROR_PROCESS;
    }
    else if(p==0)
     	printf("This is child process, id: %d, ppid: %d\n",getpid(), getppid());
    else{
	wait(NULL);
	printf("This is parent process, id: %d, ppid: %d\n", getpid(), getppid());
    }

    return 0;
}
