#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 2048

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation Failed.\n");
        exit(1);
    }
    printf("Socket Creation Successful.\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection Failed.\n");
        exit(1);
    }
    printf("Connection Established with Server.\nEnter 'exit' to leave\n");
    
    while(1) {
        // Sending message to Server 
    	printf("\nEnter message : ");
    	char msg[SIZE]; scanf("%[^\n]%*c", msg);
	    if(send(sockfd, msg, strlen(msg), 0) < 0){
            printf("Sending Failed.\n");
            exit(1);
        }
        printf("Message Sent: %s\n", msg); 

    	// Receive the server's response:
        char buff[SIZE];
    	int n = recv(sockfd, buff, sizeof(buff), 0);
        if(n < 0){
            printf("Receiving Failed.\n");
            exit(1);
        }
        buff[n] = '\0';
        printf("Server: %s\n",buff);
        if(strcmp(buff, "Bye") == 0) {
            send(sockfd, "Bye", strlen("Bye"), 0);
            break;
        }
    }
    // Close the socket:
    close(sockfd);
    return 0;
}