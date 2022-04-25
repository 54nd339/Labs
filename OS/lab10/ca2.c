#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
char *isArm(char *str){  
    int n = atoi(str);
    int temp = n, p = 0;
    while (n > 0) {
        int rem = n % 10;
        p += (rem * rem * rem);
        n /= 10;
    }
    return (temp == p) ? "True" : "False";
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
    else if (p > 0) { //Parent
        close(fd1[0]); //Close reading end of first pipe
        printf("Enter No. to be written (Parent Process) : ");
        scanf("%s", msg);
        write(fd1[1], msg, sizeof(msg));
		close(fd1[1]); //Close writing end of first pipe

		close(fd2[1]); //Close writing end of second pipe
        read(fd2[0], msg, sizeof(msg));
		printf("IsArmstrong? (Parent Process) : %s\n", msg);
		close(fd2[0]); //Close reading end of second pipe
	}
    else { //Child
		close(fd1[1]); //Close writing end of first pipe
        read(fd1[0], msg, sizeof(msg));
        printf("No. read at Child Process : %s\n",msg);
        msg = isArm(msg);
        close(fd1[0]); //Close reading end of first pipe

		close(fd2[0]); //Close reading end of second pipe
        printf("No. written at Child Process : %s\n",msg);
        write(fd2[1], msg, sizeof(msg));
		close(fd2[1]); //Close writing end of second pipe
	}
}