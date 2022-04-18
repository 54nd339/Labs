#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
    int fd1[2], fd2[2];
    char msgw1[10], msgr1[10];
    char msgw2[10], msgr2[10];
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
    else if (p > 0) {
        close(fd1[0]); //Close reading end of first pipe
        printf("Enter message1 to be written (Parent Process) : ");
        scanf("%s", msgw1);
        write(fd1[1], msgw1, sizeof(msgw1)); //Write msg in parent process
		close(fd1[1]); //Close writing end of first pipe

		wait(NULL);
        close(fd2[1]); //Close writing end of second pipe
        read(fd2[0], msgr2, sizeof(msgr2)); //Read msg in parent process
		printf("Read at Parent Process : %s\n", msgr2);
		close(fd2[0]); //Close reading end of second pipe
	}
    else {
		close(fd1[1]); //Close writing end of first pipe
        read(fd1[0], msgr1, sizeof(msgr1)); //Read msg in child process
        printf("Read at Child Process : %s\n", msgr1);
        close(fd1[0]); //Close reading end of first pipe

		close(fd2[0]); //Close reading end of second pipe
        printf("Enter message2 to be written (Child Process) : ");
        scanf("%s", msgw2);
		write(fd2[1], msgw2, sizeof(msgw2)); //Write msg in child process
		close(fd2[1]); //Close writing end of second pipe
	}
}