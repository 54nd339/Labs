#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define N 10

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    else
        printf("Socket created successfully\n");
    
    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr[N];
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Bind Failed!!\n");
        exit(1);
    }
    else
        printf("Bind Successfull!!\n");

    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Error, Couldnt Listen !!\n");
        exit(1);
    }
    else
        printf("\nListening for incoming client messages.....\n");

    
    int client_size = sizeof(cliaddr);
    int client_sock[N];
    
    for(int i = 0; i < N; i++){
        // Accept an incoming connection:
        client_sock[i] = accept(sockfd, (struct sockaddr*)&(cliaddr[i]), &client_size);

        if (client_sock[i] < 0){
            printf("Can't accept the message\n");
            exit(1);
        }
        else
            printf("Client connected at IP: %s and port: %i\n", inet_ntoa(cliaddr[i].sin_addr), ntohs(cliaddr[i].sin_port));

        while(1) {
            // Receive client's message:
            char buff[2000];
            int n = recv(client_sock[i], buff, sizeof(buff), 0);     
            buff[n] = '\0';
            if(n < 0) {
                printf("Failed to receive message.\n");
                exit(1);   
            }
            else {
                printf("Message from client: %s\n", buff);
                if(strcmp(buff, "exit") == 0) {
                    send(client_sock[i], "exit", strlen("exit"), 0);
                    break;
                }
            }
            
            // Respond to client
            printf("Enter Respose : ");
            char msg[2000]; scanf("%s", msg);
            if (send(client_sock[i], msg, strlen(msg), 0) < 0){
                printf("Sending Failed\n");
                exit(1);
            }
            else
                printf("Response : %s\n", msg);
        } 
    }
        
    // Closing the socket:
    close(sockfd);    
    return 0;
}