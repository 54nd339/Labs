#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    printf("P1 PID -> %d\n", getpid());
	for(int i=2; i<=4; i++){
		if(fork() == 0){
			printf("P%d PID -> %d\tParent PID -> %d\n",i,getpid(),getppid());
            if(i == 3){
                if(fork() == 0){
                    printf("P%d PID -> %d\tParent PID -> %d\n",i+2,getpid(),getppid());
                    for(int j=3; j<=4; j++){
                        if(fork() == 0){
                            printf("P%d PID -> %d\tParent PID -> %d\n",i+j,getpid(),getppid());
                            exit(0);
                        }
                    }
                }
            }
			exit(0);
		}
	}
    return 0;
}