#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED.\n");
        exit(1);
    }
    printf("Socket created successfully.\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4444);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed.\n");
        exit(1);
    }
    printf("Connection Established with Server.\n");
    
    while(1) {
        // Sending message to Server 
    	printf("Enter message : ");
    	char msg[2000]; scanf("%[^\n]%*c", msg);
	    if(send(sockfd, msg, strlen(msg), 0) < 0){
            printf("Failed to send message.\n");
            exit(1);
        }
        printf("Message Sent : %s\n", msg); 

    	// Receive the server's response:
        char buff[2000];
    	int n = recv(sockfd, buff, sizeof(buff), 0);
        if(n < 0){
            printf("Failed to receive message.\n");
            exit(1);
        }
        
        buff[n] = '\0';
        printf("Response from the Server: %s\n",buff);
        if(strcmp(buff, "exit") == 0) {
            send(sockfd, "exit", strlen("exit"), 0);
            break;
        }
    }
    
    // Close the socket:
    close(sockfd);
    return 0;
}