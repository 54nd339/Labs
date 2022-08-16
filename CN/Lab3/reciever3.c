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
	struct sockaddr_in recvaddr, sendaddr;
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;
		
	// Bind the socket with the port
	if (bind(sockfd, (struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		printf("Binding Failed");
		exit(1);
	}
    else 
        printf("Binding successful.\n");
	
    // Recieving message from Sender
	int len = sizeof(sendaddr), res = 0;
    int size, n = recvfrom(sockfd, &size, sizeof(int), 0,
        (struct sockaddr *)&sendaddr, &len);
    if (n == -1) {
        printf("Recieving Failed");
        exit(1);
    }
    else
        printf("Size Recieved : %d\n", size);

    for (int i = 0; i < size; i++) {
        int a;
        n = recvfrom(sockfd, &a, sizeof(int), 0,
            (struct sockaddr *)&sendaddr, &len);
        if (n == -1) {
            printf("Recieving Failed");
            exit(1);
        }
        else {
            printf("Int Recieved : %d\n", a);
            res += a;
        }
    }

    // Sending message to Sender
	int m = sendto(sockfd, &res, sizeof(int), 0,
        (const struct sockaddr *) &sendaddr, len);
    if (m == -1) {
        printf("Sending Failed.");
        exit(1);
    }
    else 
	    printf("\nResult sent : %d\n", res);
		
	return 0;
}