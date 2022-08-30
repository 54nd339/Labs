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
		printf("Socket Creation FAILED.\n");
		exit(1);
	}
    else
        printf("Socket created successfully.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;
		
    while(1) {
        // Sending message to reciever
        printf("Enter Message : ");
        char msg[100]; scanf("%s", msg);
        int m = sendto(sockfd, (char *)msg, strlen(msg), 0,
            (struct sockaddr *) &recvaddr, sizeof(recvaddr));
        if (m == -1) {
            printf("Failed to send message.\n");
            exit(1);
        }
        else
            printf("Message sent : %s\n", msg);

        // Receiving message from reciever
        char buffer[100];
        int len, n = recvfrom(sockfd, (char *)buffer, 100, 0,
            (struct sockaddr *) &recvaddr, &len);
        if (n == -1) {
            printf("Failed to receive message.\n");
            exit(1);
        }
        else {
            buffer[n] = '\0';
            printf("Response from the Server: %s\n",buffer);
            if(strcmp(buffer, "exit") == 0) {
                sendto(sockfd, "exit", strlen("exit"), 0, (struct sockaddr *) &recvaddr, sizeof(recvaddr));
                break;
            }	
        }
    }

	return 0;
}