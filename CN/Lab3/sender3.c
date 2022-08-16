#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080

int main() {	
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
		exit(1);
	}
    else
        printf("Socket created successfully.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;

    // Sending msgessage to reciever
	printf("Enter No. of ints to be entered : ");
    int size; scanf("%d", &size);
    int m = sendto(sockfd, &size, sizeof(int), 0,
        (const struct sockaddr *) &recvaddr, sizeof(recvaddr));
    if (m == -1) {
        printf("Sending Failed.");
        exit(1);
    }
    else
        printf("Array Size Sent.\n");

    for(int i = 0; i < size; i++) {
        printf("Enter int %d : ", i+1);
        int a; scanf("%d", &a);
        m = sendto(sockfd, &a, sizeof(int), 0,
            (const struct sockaddr *)&recvaddr, sizeof(recvaddr));
        if (m == -1) {
            printf("Sending Failed.");
            exit(1);
        }
        else
            printf("INT Sent : %d\n", a);
    }

    // Receiving message from reciever
	int res, len, n = recvfrom(sockfd, &res, sizeof(int), 0,
        (struct sockaddr *) &recvaddr, &len);
	if (n == -1) {
        printf("Recieving Failed");
        exit(1);
    }
    else
        printf("Result Recieved : %d\n", res);
	
	close(sockfd);
	return 0;
}