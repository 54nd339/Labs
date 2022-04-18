#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
void revstr(char *str){  
    int len = strlen(str);
    for (int i = 0; i < len/2; i++){
        char temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }
    printf ("\nAfter the reverse of the message : %s ",str); 
}  
int main(){
    int pipefds[2];
    char msgw[10], msgr[10];
    if(pipe(pipefds) == -1){
        printf("Unable to create pipe.");
        return 1;
    }
    if(fork() == 0){
        read(pipefds[0], msgr, sizeof(msgr));
        printf("Read message from pipe : %s", msgr);
        revstr(msgr); 
    }
    else{
        printf("Enter message to be written : ");
        scanf("%s", msgw);
        write(pipefds[1], msgw, sizeof(msgw));
        sleep(2);
    }
}