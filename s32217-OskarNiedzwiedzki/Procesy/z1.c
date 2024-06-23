#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
    printf("This process id is: %d\n Parent process id is: %d", getpid(), getppid());
    while(1)getchar();
}
