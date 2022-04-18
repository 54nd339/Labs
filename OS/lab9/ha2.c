#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main(){
    int pipefds[2];
    char msgw[2][10], msgr[2][10];
    if(pipe(pipefds) == -1){
        printf("Unable to create pipe.");
        return 1;
    }
    if(fork() == 0){
        read(pipefds[0], msgr[0], sizeof(msgr[0]));
        printf("Read message1 from pipe : %s\n", msgr[0]);
        read(pipefds[0], msgr[1], sizeof(msgr[1]));
        printf("Read message2 from pipe : %s\n", msgr[1]);
    }
    else{
        printf("Enter message1 to be written : ");
        scanf("%s", msgw[0]);
        write(pipefds[1], msgw[0], sizeof(msgw[0]));
        sleep(1);
        printf("Enter message2 to be written : ");
        scanf("%s", msgw[1]);
        write(pipefds[1], msgw[1], sizeof(msgw[1]));
        sleep(1);
    }
}