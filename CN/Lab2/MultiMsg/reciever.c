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
		printf("Socket Creation Failed.\n");
		exit(1);
	}
    printf("Socket Creation Successful.\n");

	// Filling server information
	struct sockaddr_in recvaddr, sendaddr;
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;

	// Bind the socket with the port
	if (bind(sockfd, (const struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		printf("Port Binding Failed.");
		exit(1);
	}
    printf("Binding Successful with PORT: %d\n", PORT);
	
    while(1) {
        // Receiving message from Sender
        char buffer[SIZE];
        int len = sizeof(sendaddr);
        int n = recvfrom(sockfd, (char *)buffer, SIZE, 0,
            (struct sockaddr *)&sendaddr, &len);
        if (n == -1) {
            printf("Receiving Failed.\n");
            exit(1);
        }

        buffer[n] = '\0';
        printf("\nClient: %s\n", buffer);
        if(strcmp(buffer, "exit") == 0) {
            sendto(sockfd, "Bye", strlen("Bye"), 0, (struct sockaddr *) &sendaddr, len);
            printf("Server Exiting.\n");
            break;
        }

        // Sending message to Sender
        printf("Enter Response: ");
        char msg[SIZE]; scanf("%[^\n]%*c", msg);
        int m = sendto(sockfd, (char *)msg, strlen(msg), 0,
            (struct sockaddr *) &sendaddr, len);
        if (m == -1) {
            printf("Sending Failed.");
            exit(1);
        }
        printf("Response: %s\n", msg);
    }
    close(sockfd);
	return 0;
}