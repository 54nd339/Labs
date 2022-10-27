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
	struct sockaddr_in recvaddr;
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;
		
    while(1) {
        // Sending message to reciever
        printf("\nEnter Message : ");
        char msg[SIZE];  scanf("%[^\n]%*c", msg);
        int m = sendto(sockfd, (char *)msg, strlen(msg), 0,
            (struct sockaddr *) &recvaddr, sizeof(recvaddr));
        if (m == -1) {
            printf("Sending Failed.\n");
            exit(1);
        }
        printf("Message sent: %s\n", msg);

        // Receiving message from reciever
        char buffer[SIZE];
        int len, n = recvfrom(sockfd, (char *)buffer, SIZE, 0,
            (struct sockaddr *) &recvaddr, &len);
        if (n == -1) {
            printf("Receiving Failed.\n");
            exit(1);
        }

        buffer[n] = '\0';
        printf("Server: %s\n",buffer);
        if(strcmp(buffer, "Bye") == 0) {
            break;
        }	
    }
    close(sockfd);
	return 0;
}