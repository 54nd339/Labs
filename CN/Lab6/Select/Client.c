#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080
#define SIZE 2048

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
    printf("Connection Established with Server.\nEnter 'exit' to leave\n");

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    FD_SET(0, &readfds); 
    int fdmax = sockfd;

    while(1) {
        fd_set temp = readfds;
        if(select(fdmax+1, &temp, NULL, NULL, NULL) == -1) {
            printf("ERROR: select failed");
            exit(1);
        }
        for(int i = 0; i <= fdmax; i++) {
            if(FD_ISSET(i, &temp)) {
                if(i == sockfd) {   // check if it's the server
                    char buff[SIZE]; int n;
                    if((n = recv(sockfd, buff, SIZE, 0)) < 0) {
                        printf("Receiving Failed.\n");
                        exit(1);
                    }
                    else if(n == 0) {
                        printf("Server Disconnected.\n");
                        exit(1);
                    }
                    buff[n] = '\0';
                    printf("\n%s", buff);
                }
                else {              // check if user typed a message
                    char msg[SIZE];
                    fgets(msg, SIZE, stdin);
                    if(strcmp(msg, "logout\n") == 0) {
                        printf("Client Disconnected.\n");
                        exit(1);
                    }
                    if(send(sockfd, msg, strlen(msg), 0) < 0) {
                        printf("Sending Failed.\n");
                        exit(1);
                    }
                    printf("You: %s", msg);
                }
            }
        }
    }
    // Close the socket:
    close(sockfd);
    return 0;
}