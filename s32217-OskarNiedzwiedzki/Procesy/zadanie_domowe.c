#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

void create_subprocess();
void create_process();

int main(){
	char buffer[32];
	create_process();/*B*/
	create_process();/*C*/
	sleep(1);

	sprintf(buffer, "pstree -sc %d", getpid());
	system(buffer);
        wait(NULL);/*wait for B*/
	printf("process exited\n");
	wait(NULL);
	printf("process exited\n");

	return 0;
}

/*creates child subprocess*/
void create_subprocess(){
	if(fork()==0){
		sleep(10);
		exit(0);
	}
	else return;
}

/*creates process with 2 children*/
void create_process(){
	if(fork()==0){
		create_subprocess();
		create_subprocess();
		wait(NULL);
		exit(0);
	}
	else return;
}
