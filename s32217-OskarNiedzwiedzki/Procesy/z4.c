#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>/*change name of process using prctl()*/
#include <sys/types.h>/*pid_t*/

#define NUM_CHILDREN 10
#define _ERROR_PROCESS 1

int main() {
    int i=0;
    pid_t child_pid=0;
    char buffer[64];
    char process_name[16]; /*16 bytes is the limit in linux*/

    for (i = 1; i <= NUM_CHILDREN; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("child process could not be created");
            return _ERROR_PROCESS;
        } 
	else if (child_pid == 0){	/*Child process has been created, change its name for cool one*/
		sprintf(process_name, "process%d",i);
		if(prctl(PR_SET_NAME, (unsigned long)process_name) < 0) /*set process name, handle errors*/
			perror("prctl() - name  could not be changed");
	}
	else {
            wait(NULL);/*wait for child process to end*/
	    sprintf(buffer, "pstree -s %d", getpid()); /*print process tree*/
	    system(buffer);
            return 0; /*end process*/
        }
    }

    return 0;
}

