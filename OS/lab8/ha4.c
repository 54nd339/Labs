#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    printf("P1 PID -> %d\n", getpid());
	if(fork() == 0){
		printf("P2 PID -> %d\tParent PID -> %d\n",getpid(),getppid());
        if(fork() == 0){
            printf("P3 PID -> %d\tParent PID -> %d\n",getpid(),getppid());
            if(fork() == 0){
                printf("P4 PID -> %d\tParent PID -> %d\n",getpid(),getppid());
            }
        }
	}
	return 0;
}