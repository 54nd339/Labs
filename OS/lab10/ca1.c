#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
char *revstr(char *str){  
    int len = strlen(str);
    for (int i = 0; i < len/2; i++){
        char temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }
    return str; 
}  

int main(){
    int fd1[2], fd2[2];
    char *msg = malloc(10*sizeof(char));
    if (pipe(fd1) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	if (pipe(fd2) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}

	pid_t p = fork();
    if (p < 0) {
		fprintf(stderr, "fork Failed");
		return 1;
	}
    else if (p == 0) { //Child
        close(fd1[0]); //Close reading end of first pipe
        printf("Enter String to be written (Child Process) : ");
        scanf("%s", msg);
        write(fd1[1], msg, sizeof(msg));
		close(fd1[1]); //Close writing end of first pipe

		close(fd2[1]); //Close writing end of second pipe
        read(fd2[0], msg, sizeof(msg));
		printf("Reversed String (Child Process) : %s\n", msg);
		close(fd2[0]); //Close reading end of second pipe
	}
    else { //Parent
		close(fd1[1]); //Close writing end of first pipe
        read(fd1[0], msg, sizeof(msg));
        printf("Message read at Parent Process : %s\n",msg);
        msg = revstr(msg);
        close(fd1[0]); //Close reading end of first pipe

		close(fd2[0]); //Close reading end of second pipe
        printf("Message written at Parent Process : %s\n",msg);
        write(fd2[1], msg, sizeof(msg));
		close(fd2[1]); //Close writing end of second pipe
	}
}