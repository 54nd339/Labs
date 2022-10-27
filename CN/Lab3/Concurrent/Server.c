#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 2048
#define N 10

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation Failed.\n");
        exit(1);
    }
    printf("Socket Creation Successful.\n");

    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr[N];
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Port Binding Failed.\n");
        exit(1);
    }
    printf("Bind Successfull with PORT: %d\n", PORT);

    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Server Listening Failed.\n");
        exit(1);
    }
    printf("\nServer Listening..\n");
    
    int clisize = sizeof(cliaddr);
    int newSock[N];
    for(int i = 0; i < N; i++){
        // Accept an incoming connection:
        newSock[i] = accept(sockfd, (struct sockaddr*)&(cliaddr[i]), &clisize);
        if(newSock[i] < 0){
            printf("Error Accepting Client\n");
            exit(1);
        }
        printf("Client connected from %s:%i\n",
        inet_ntoa(cliaddr[i].sin_addr), ntohs(cliaddr[i].sin_port));

        while(1) {
            // Receive client's message:
            char buff[SIZE];
            int n = recv(newSock[i], buff, sizeof(buff), 0);
            if(n < 0) {
                printf("Receiving Failed.\n");
                exit(1);   
            }

            buff[n] = '\0';
            printf("\nClient: %s\n", buff);
            if(strcmp(buff, "exit") == 0) {
                send(newSock[i], "Bye", strlen("Bye"), 0);
                printf("Client Disconnected from %s:%i\n",
                inet_ntoa(cliaddr[i].sin_addr), ntohs(cliaddr[i].sin_port));
                close(newSock); break;
            }
            
            // Respond to client:
            printf("Enter Respose : ");
            char msg[SIZE]; scanf("%[^\n]%*c", msg);
            if(send(newSock[i], msg, strlen(msg), 0) < 0){
                printf("Sending Failed.\n");
                exit(1);
            }
            printf("Response: %s\n", msg);
        } 
    }

    // Closing the socket:
    close(sockfd);    
    return 0;
}