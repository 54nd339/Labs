#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define SIZE 1024

int main() {	
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket Creation Failed");
		exit(1);
	}
    printf("Socket Creation Successful.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;
		
    // Binding socket to port 5000
    // if (bind(sockfd, (const struct sockaddr*)&recvaddr, sizeof(recvaddr)) == -1) {
	// 	perror("Port Binding Failed.");
	// 	exit(1);
	// }
    // printf("Binding successful.\n");

    // Sending msgessage to reciever
	char *msg = "Hello from sender";
	int m = sendto(sockfd, (const char *)msg, strlen(msg), 0,
        (const struct sockaddr *) &recvaddr, sizeof(recvaddr));
	if (m == -1) {
        printf("Sending Failed.");
        exit(1);
    }
    printf("Hello message sent.\n");
	
    // Receiving message from reciever
	char buffer[100];
	int len, n = recvfrom(sockfd, (char *)buffer, 100, 0,
        (struct sockaddr *) &recvaddr, &len);
	if (n == -1) {
        printf("Receiving Failed");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Reciever: %s\n", buffer);
	
	close(sockfd);
	return 0;
}