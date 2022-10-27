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
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0) {
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
    if(bind(listener, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Port Binding Failed.\n");
        exit(1);
    }
    printf("Bind Successfull with PORT: %d\n", PORT);

    // Listen for clients:
    if(listen(listener, 1) < 0){
        printf("Server Listening Failed.\n");
        exit(1);
    }
    printf("\nServer Listening..\n");

    // Set listener socket to allow multiple connections
    int option = 1;
    if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int)) == -1) {
        printf("ERROR: setsockopt failed");
        exit(1);
    }
   
    fd_set master;              // master file descriptor list
    fd_set read_fds;            // temp file descriptor list for select()
    FD_ZERO(&master);           // clear the master and temp sets
    FD_ZERO(&read_fds);
    FD_SET(listener, &master);  // add the listener to the master set
    int fdmax = listener;       // keep track of the biggest file descriptor
    
    while(1) {
        read_fds = master;
        if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("ERROR: select failed");
            exit(1);
        }
        // Run through the existing connections looking for data to read
        for(int i = 0; i <= fdmax; i++) {
            if(FD_ISSET(i, &read_fds)) {
                if(i == listener) { // Handle new connections
                    int addrlen = sizeof(cliaddr);
                    int newfd = accept(listener, (struct sockaddr *)&cliaddr, &addrlen);
                    if(newfd == -1)
                        printf("Error Accepting Client\n");
                    else {
                        FD_SET(newfd, &master);            // add to master set
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
                            if(FD_ISSET(j, &master)) {
                                if(j != listener && j != i) {
                                    if(send(j, buf, n, 0) < 0) {
                                        printf("Sending Failed."); break;
                                    }
                                }
                            }
                        }
                    }
                    else if(n == 0)
                        printf("Server: %s:%d hung up\n",
                            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    else {
                        printf("Recieving Failed.\n");
                        close(i); FD_CLR(i, &master); // remove from master set
                    }
                }
            }
        }
    }

    // Close the socket:
    close(listener);
    return 0;
}