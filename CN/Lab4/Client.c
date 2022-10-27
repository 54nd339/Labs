#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int recvFile(char *filename, int sockfd) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error in Writing File.");
        exit(1);
    }
    // File transfer:
    char data[SIZE] = {0}; int flag = 1;
    while(1) {
        if(recv(sockfd, data, SIZE, 0) == -1) {
            printf("Error in Receiving File.");
            exit(1);
        }
        if(data[0] == EOF) break;
        if(strcmp(data, "File not found.") == 0) {
            flag = 0; break;
        }
        fprintf(fp, "%s", data);
        bzero(data, SIZE);
    }
    fclose(fp);
    if(!flag) system("rm rfile");
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
    printf("Connection Established with Server.\n");
    
    // Receive list from server:
    recvFile("rlist", sockfd);
    printf("\nFile List:\n");
    system("cat rlist && rm rlist");

    // Send filename to server:
    printf("\nEnter Name of File to be Downloaded: ");
    char filename[SIZE]; scanf("%[^\n]%*c", filename);
    send(sockfd, filename, sizeof(filename), 0);
    printf("File requested successfully !!\n");

    // Receive file from server:
    if(recvFile("rfile", sockfd)) {
        printf("File downloaded successfully !!\n");
        printf("\nFile contents:\n");
        system("cat rfile");
    }
    else printf("File not found !!\n");
    
    // Close the socket:
    close(sockfd);
    return 0;
}