#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#define PORT 9034

int main() {
    // Create socket:
    int listener;
    if ((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("listener socket creation failed");
        exit(1);
    }
    printf("listener socket created successfully.\n");

    // set listener socket to allow multiple connections
    int yes = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        printf("setsockopt failed");
        exit(1);
    }

    // fill in address info
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    // bind the socket to the port
    if (bind(listener, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("binding failed");
        exit(1);
    }
    printf("binding successful.\n");

    // listen
    if (listen(listener, 10) == -1) {
        printf("listening failed");
        exit(1);
    }
    printf("listening for connections..  .\n");
   
    fd_set master;      // master file descriptor list
    fd_set read_fds;    // temp file descriptor list for select()
    FD_ZERO(&master);   // clear the master and temp sets
    FD_ZERO(&read_fds);
    FD_SET(listener, &master);  // add the listener to the master set
    int fdmax = listener;       // keep track of the biggest file descriptor
    // main loop
    while(1) {
        read_fds = master; // copy it
        if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("select failed");
            exit(1);
        }
        // run through the existing connections looking for data to read
        for(int i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == listener) {
                    // handle new connections
                    int addrlen = sizeof(cliaddr);
                    int newfd; // newly accept()ed socket descriptor
                    if ((newfd = accept(listener, (struct sockaddr *)&cliaddr, &addrlen)) == -1)
                        printf("accept failed");
                    else {
                        FD_SET(newfd, &master);             // add to master set
                        if (newfd > fdmax) fdmax = newfd;   // keep track of the maximum
                        printf("selectserver: new connection from %s:%d\n",
                        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    }
                }
                else {
                    int nbytes; char buf[256]; // buffer for client data
                    // handle data from a client
                    if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0) {
                        // got error or connection closed by client
                        if (nbytes == 0) // connection closed
                            printf("selectserver: connection at %s:%d hung up\n",
                            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                        else
                            printf("recv failed");
                        close(i); // bye!
                        FD_CLR(i, &master); // remove from master set
                    }
                    else { // we got some data from a client
                        for(int j = 0; j <= fdmax; j++) { // send to everyone!
                            if (FD_ISSET(j, &master)) {
                                // except the listener and ourselves
                                if (j != listener && j != i)
                                    if (send(j, buf, nbytes, 0) == -1)
                                        printf("sending failed");
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}