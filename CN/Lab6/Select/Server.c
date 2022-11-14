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
    if(sockfd < 0) {
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

    // Set sockfd socket to allow multiple connections
    int option = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int)) == -1) {
        printf("ERROR: setsockopt failed");
        exit(1);
    }
   
    fd_set readfds;             // readfds file descriptor list
    FD_ZERO(&readfds);          // clear the readfds and temp sets
    FD_SET(sockfd, &readfds);   // add the sockfd to the readfds set
    int fdmax = sockfd;         // keep track of the biggest file descriptor
    
    while(1) {
        fd_set temp = readfds;
        if(select(fdmax+1, &temp, NULL, NULL, NULL) == -1) {
            printf("ERROR: select failed");
            exit(1);
        }
        // Run through the existing connections looking for data to read
        for(int i = 0; i <= fdmax; i++) {
            if(FD_ISSET(i, &temp)) {
                if(i == sockfd) { // Handle new connections
                    int addrlen = sizeof(cliaddr);
                    int newfd = accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen);
                    if(newfd == -1)
                        printf("Error Accepting Client\n");
                    else {
                        FD_SET(newfd, &readfds);            // add to readfds set
                        if(newfd > fdmax) fdmax = newfd;   // keep track of the maximum
                        printf("Server: new connection from %s:%d\n",
                        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    }
                }
                else {  // Handle data from a client
                    char buf[SIZE];
                    int n = recv(i, buf, sizeof(buf), 0);
                    if(n > 0) {  // Send to Everyone
                        for(int j = 0; j <= fdmax; j++) {
                            if(FD_ISSET(j, &readfds)) {
                                if(j != sockfd && j != i) {
                                    if(send(j, buf, n, 0) < 0) {
                                        printf("Sending Failed."); break;
                                    }
                                }
                            }
                        }
                    }
                    else if(n == 0) {
                        printf("Server: %s:%d hung up\n",
                            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                        close(i); FD_CLR(i, &readfds);
                    }
                    else {
                        printf("Recieving Failed.\n");
                        close(i); FD_CLR(i, &readfds); // remove from readfds set
                    }
                }
            }
        }
    }

    // Close the socket:
    close(sockfd);
    return 0;
}