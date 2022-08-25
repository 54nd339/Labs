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
	if (bind(sockfd, (const struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		printf("Binding Failed");
		exit(1);
	}
    else 
        printf("Binding successful.\n");
	
    // Receiving message from Sender
	int len = sizeof(sendaddr);
    int ar[2];
    for(int i = 0; i < 2; i++) {
        int n = recvfrom(sockfd, &ar[i], sizeof(int), 0,
            (struct sockaddr *)&sendaddr, &len);
        if (n == -1) {
            printf("Receiving Failed");
            exit(1);
        }
        else
            printf("INT Received : %d\n", ar[i]);
    }

    // Sending message to Sender
	int res = ar[0] + ar[1];
	int m = sendto(sockfd, &res, sizeof(int), 0,
        (const struct sockaddr *) &sendaddr, len);
    if (m == -1) {
        printf("Sending Failed.");
        exit(1);
    }
    else 
	    printf("Result sent : %d\n", res);
		
	return 0;
}