#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SIZE 1024

int sendFile(char *filename, int sockfd) {
    FILE *fp = fopen(filename, "r");
    char data[SIZE] = {0}; int flag = 0;
    if (fp == NULL) {
        // File not found:
        strcpy(data, "File not found.");
        send(sockfd, data, sizeof(data), 0);
        printf("%s\n", data);
    }
    else {
        // File transfer:
        printf("Transferring File....");
        while(fgets(data, SIZE, fp) != NULL) {
            if(send(sockfd, data, sizeof(data), 0) == -1) {
                printf("Error in sending file.");
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
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    printf("Socket created successfully\n");

    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Bind Failed!!\n");
        exit(1);
    }
    printf("Bind Successfull!!\n");

    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Error, Couldnt Listen !!\n");
        exit(1);
    }
    printf("\nListening for incoming client messages..\n");

    // Accept an incoming connection:
    int client_size = sizeof(cliaddr);
    int client_sock = accept(sockfd, (struct sockaddr*)&cliaddr, &client_size);

    if (client_sock < 0){
        printf("Can't accept the message\n");
        exit(1);
    }
    printf("Client connected at IP: %s and port: %i\n",
        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    // Create list of files and send to client:
    system("ls >> list");
    if(sendFile("list", client_sock))
        printf("List sent successfully.\n");

    // Request file from client:
    char filename[SIZE];
    if(recv(client_sock, filename, SIZE, 0) < 0) {
        printf("Error in receiving filename.");
        exit(1);
    }
    printf("File requested: %s\n", filename);

    // Send file to client:
    if(sendFile(filename, client_sock))
        printf("File sent successfully.\n");

    // Closing the socket:
    system("rm list");  
    close(client_sock);
    close(sockfd);
    return 0;
}