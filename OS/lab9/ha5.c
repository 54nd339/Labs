#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
    int fd1[2], fd2[2];
    char msg1[10], msg2[10];
    printf("Enter message1 (Written By Parent, Read by Child) : ");
    scanf("%s", msg1);
    printf("Enter message2 (Written By Child, Read by Parent) : ");
    scanf("%s", msg2);
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
        write(fd1[1], msg1, sizeof(msg1));
        printf("Written at Parent Process : %s\n", msg1);
        close(fd1[1]); //Close writing end of first pipe

        wait(NULL);
        close(fd2[1]); //Close writing end of second pipe
        read(fd2[0], msg2, sizeof(msg2));
        printf("Read at Parent Process : %s\n", msg2);
        close(fd2[0]); //Close reading end of second pipe
	}
    else {
        close(fd1[1]); //Close writing end of first pipe
        read(fd1[0], msg1, sizeof(msg1));
        printf("Read at Child Process : %s\n", msg2);
        close(fd1[0]); //Close reading end of first pipe

		close(fd2[0]); //Close reading end of second pipe
        write(fd2[1], msg2, sizeof(msg2));
        printf("Written at Child Process : %s\n", msg1);
        close(fd2[1]); //Close reading end of second pipe
	}
}