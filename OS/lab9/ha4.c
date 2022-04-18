#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(){
    int pipefds[2];
    char msgw[10], msgr[10];
    if(pipe(pipefds) == -1){
        printf("Unable to create pipe.");
        return 1;
    }
    if(fork() == 0){
        printf("Enter message to be written : ");
        scanf("%s", msgw);
        write(pipefds[1], msgw, sizeof(msgw));
        sleep(2);
    }
    else{
        //wait(NULL);
        read(pipefds[0], msgr, sizeof(msgr));
        printf("Read message from pipe : %s", msgr);
    }
}