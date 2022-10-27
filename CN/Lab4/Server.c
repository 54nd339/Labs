#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int sendFile(char *filename, int sockfd) {
    FILE *fp = fopen(filename, "r");
    char data[SIZE] = {0}; int flag = 0;
    if(fp == NULL) {
        // File not found:
        strcpy(data, "File Not Found.");
        send(sockfd, data, sizeof(data), 0);
        printf("%s\n", data);
    }
    else {
        // File transfer:
        printf("\nTransferring File....");
        while(fgets(data, SIZE, fp) != NULL) {
            if(send(sockfd, data, sizeof(data), 0) == -1) {
                printf("Error in Sending File.");
                exit(1);
            }
            bzero(data, SIZE);
        }
        flag = 1; fclose(fp);
    }
    // Send EOF:
    char eof = EOF;
    send(sockfd, &eof, sizeof(eof), 0);
    return flag;
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation Failed.\n");
        exit(1);
    }
    printf("Socket Creation Successful.\n");

    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr;
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

    // Accept an incoming connection:
    int clisize = sizeof(cliaddr);
    int newSock = accept(sockfd, (struct sockaddr*)&cliaddr, &clisize);

    if(newSock < 0){
        printf("Error Accepting Client\n");
        exit(1);
    }
    printf("Client connected from %s:%i\n",
    inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    // Create list of files and send to client:
    system("ls >> list");
    if(sendFile("list", newSock))
        printf("\nList sent successfully.\n");

    // Request file from client:
    char filename[SIZE];
    if(recv(newSock, filename, SIZE, 0) < 0) {
        printf("Error Receiving Filename.");
        exit(1);
    }
    printf("File requested: %s\n", filename);

    // Send file to client:
    if(sendFile(filename, newSock))
        printf("\nFile sent successfully.\n");

    // Closing the socket:
    system("rm list");  
    close(newSock);
    close(sockfd);
    return 0;
}