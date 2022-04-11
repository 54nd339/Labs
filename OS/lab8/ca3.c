#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    printf("PID -> %d\n", getpid());
    int pid = fork();
    if(pid == 0){
        printf("PID -> %d\tPPID -> %d\n", getpid(), getppid());
        sleep(2);
    }
    else{
        pid = fork();
        if(pid == 0){
            printf("PID -> %d\tPPID -> %d\n", getpid(), getppid());
            sleep(2);
        }
        else{
           pid = fork();
            if(pid == 0){
                printf("PID -> %d\tPPID -> %d\n", getpid(), getppid());
                sleep(2);
            }
        }
    }
}