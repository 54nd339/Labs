#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    printf("PID -> %d\n", getpid());
    for(int i=1; i<=2; i++){
		if(fork() == 0){
            printf("PID -> %d\tParent PID -> %d\n",getpid(),getppid());
            for(int j=1; j<=2; j++){
                if(fork() == 0){
                    printf("PID -> %d\tParent PID -> %d\n",getpid(),getppid());
                    if(i == 1 && j == 2){
                        for(int k=1; k<=2; k++){
                            if(fork() == 0){
                                printf("PID -> %d\tParent PID -> %d\n",getpid(),getppid());
                                exit(0);
                            }
                            else sleep(2);
                        }
                    }
                    exit(0);
                }
                else sleep(2);
            }
            exit(0);
        }
        else sleep(2);
	}
	return 0;
}