#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE  1024

int main(void)
{
    int sockfd, client_sock, client_size;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char server_message[MAXLINE], client_message[MAXLINE];
    
    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    // Create socket:
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        return -1;
    }
    printf("Socket created successfully\n");
    
    // Set port and IP:
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0){
        printf("Bind Failed!!\n");
        return -1;
    }
    printf("Bind Successfull!!\n");
    
    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Error, Couldnt Listen !!\n");
        return -1;
    }
    printf("\nListening for incoming client messages.....\n");
    
    // Accept an incoming connection:
    client_size = sizeof(cliaddr);
    client_sock = accept(sockfd, (struct sockaddr*)&cliaddr, &client_size);
    
    if (client_sock < 0){
        printf("Can't accept the message\n");
        return -1;
    }
    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
    
   int n;
int len = sizeof(cliaddr);
   while(1){
    // Receive client's message:
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        
	buffer[n] = '\0';
    	
    	printf("Message from client: %s\n", buffer);
	if(strcmp(buffer, "exit") == 0)
	    {
	    	sendto(sockfd, "exit", strlen("exit"), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
		//close(sockfd);
    		return 0;
    	}
    
    	// Respond to client:
	printf("Enter a respose to be sent to client:");
	scanf("%s", server_message);
    	//strcpy(server_message, "Hellu Client.");
    
    	sendto(sockfd, server_message, strlen(server_message), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
	
  }
    
    // Closing the socket:
    
    
    return 0;
}
