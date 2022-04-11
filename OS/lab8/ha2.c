#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    printf("Parent PID -> %d\n", getpid());
	for(int i=1; i<=3; i++){
		if(fork() == 0) {
			printf("Child%d PID -> %d\tParent PID -> %d\n",i,getpid(),getppid());
			exit(0);
		}
	}
    return 0;	
}