// Write TCP program in C where both client and server send messages to each other. If one of them sends exit then connection closes

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAXLINE 2000
int main(void)
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAXLINE];
    char server_message[MAXLINE], client_message[MAXLINE];
    
    // Clean buffers:
    memset(server_message,'\0',sizeof(server_message));
    memset(client_message,'\0',sizeof(client_message));
    
    // Create socket:
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0){
        printf("Socket Creation Failed!!\n");
        return -1;
    }
    
    printf("Socket created successfully\n");
    
    // Set port and IP the same as server-side:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed!!\n");
        return -1;
    }
    printf("Connection with server Processed Successfully !!\n");
    
   int n;
   int len ;
    while(1){
    	// Get input from the user:
    	printf("Enter message to be sent to the server: ");
    	scanf("%s", client_message);
	sendto(sockfd, client_message, strlen(client_message), MSG_CONFIRM, (const struct sockaddr *) &server_addr, sizeof(server_addr));    
    	
    
    	// Receive the server's response:
    	 n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &server_addr, &len);
	 
	buffer[n] = '\0';
	printf("Response from the Server: %s\n",buffer);
	if(strcmp(buffer, "exit") == 0)
    	{
    		sendto(sockfd, "exit", strlen("exit"), MSG_CONFIRM, (const struct sockaddr *) &server_addr, sizeof(server_addr));
    		close(sockfd);
    		return 0;
    	}
	
    
    	
   }
    
    // Close the socket:
    close(sockfd);
    
    return 0;
}
