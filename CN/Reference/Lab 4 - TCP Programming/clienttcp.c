#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
    int sockfd;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    
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
    
    // Get input from the user:
    printf("Enter message to be sent to the server: ");
    gets(client_message);
    
    // Send the message to server:
    if(send(sockfd, client_message, strlen(client_message), 0) < 0){
        printf("Failed to send message\n");
        return -1;
    }
    
    // Receive the server's response:
    if(recv(sockfd, server_message, sizeof(server_message), 0) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
    
    printf("Response from the Server: %s\n",server_message);
    
    // Close the socket:
    close(sockfd);
    
    return 0;
}