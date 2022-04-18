#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    printf("PID -> %d\n", getpid());
    for(int i=1; i<=2; i++){
		if(fork() == 0){
            printf("PID -> %d\tParent PID -> %d\n",getpid(),getppid());
            if(fork() == 0){
                printf("PID -> %d\tParent PID -> %d\n",getpid(),getppid());
                exit(0);
            }
            else sleep(2);
            exit(0);
        }
        else sleep(2);
	}
	return 0;
}