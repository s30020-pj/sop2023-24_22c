#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define CHILDREN_NUM 100
#define _ERROR_PROCESS 1

int main(int argc, char** argv){
	int i=0;
	pid_t children_id[CHILDREN_NUM];
	char buffer[64];

	/*create all child process*/
	for(i=0;i<CHILDREN_NUM;i++){
		children_id[i] = fork();
		if(children_id[i]<0){
			perror("fork() - child process could not be created");
			return _ERROR_PROCESS;
		}
		else if(children_id[i]==0)
			return 0;
	}
	printf("\n\n[Process tree]\n");
	sprintf(buffer, "pstree -s %d", getpid());
	system(buffer);
	
	/*parent process, wait for all children to end*/
	for(i=0;i<CHILDREN_NUM;i++){
		printf("Waiting for process[%d]",children_id[i]);
		waitpid(children_id[i],NULL,0);
		printf(" - Ended\n");
	}

	return 0;
}
