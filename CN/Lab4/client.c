#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SIZE 1024

void recvFile(char *filename, int sockfd) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in writing file.");
        exit(1);
    }
    // File transfer:
    char data[SIZE] = {0};
    while(recv(sockfd, data, SIZE, 0) > 0) {
        if(strcmp(data, "EOF") == 0) break;
        fprintf(fp, "%s", data);
        bzero(data, SIZE);
    }
    fclose(fp);
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    printf("Socket created successfully\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed!!\n");
        exit(1);
    }
    printf("Connection with server Processed Successfully !!\n");
    
    // Receive list from server:
    recvFile("rlist", sockfd);
    printf("List received successfully :\n");
    system("cat rlist && rm rlist");

    // Send filename to server:
    printf("Name of file to be downloaded: ");
    char filename[SIZE]; scanf("%s", filename);
    send(sockfd, filename, sizeof(filename), 0);
    printf("File requested successfully !!\n");

    // Receive file from server:
    recvFile("rfile", sockfd);
    printf("File received successfully !!\n");
    
    // Close the socket:
    close(sockfd);
    return 0;
}