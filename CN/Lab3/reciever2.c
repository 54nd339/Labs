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
		perror("Socket creation failed");
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
		perror("Binding Failed");
		exit(1);
	}
    else 
        printf("Binding successful.\n");
	
    // Reciving message from Sender
	char buffer[100];
	int len = sizeof(sendaddr);
	int n = recvfrom(sockfd, (char *)buffer, 100, 0,
        (struct sockaddr *)&sendaddr, &len);
    if (n == -1) {
        printf("Recieving Failed");
        exit(1);
    }
    else {
        buffer[n] = '\0';
        printf("Sender : %s\n", buffer);
    }

    // Sending message to Sender
	char *msg = "Hello from Reciever";
	int m = sendto(sockfd, (const char *)msg, strlen(msg), 0,
        (const struct sockaddr *) &sendaddr, len);
    if (m == -1) {
        perror("Sending Failed.");
        exit(1);
    }
    else 
	    printf("Hello message sent.\n");
		
	return 0;
}