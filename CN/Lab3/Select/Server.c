#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 9034 // port we’re listening on

int main(void) {
    // get the listener
    int listener; // listening socket descriptor
    if ((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("listener socket creation failed");
        exit(1);
    }
    printf("listener socket created successfully.\n");

    // lose the pesky "address already in use" error message
    int yes = 1; // for setsockopt() SO_REUSEADDR, below
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        printf("setsockopt failed");
        exit(1);
    }
    printf("setsockopt successful.\n");

    // bind
    struct sockaddr_in myaddr; // server address
    struct sockaddr_in remoteaddr; // client address
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(PORT);
    myaddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(myaddr.sin_zero), '\0', 8);
    if (bind(listener, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1) {
        printf("binding failed");
        exit(1);
    }
    printf("binding successful.\n");

    // listen
    if (listen(listener, 10) == -1) {
        printf("listening failed");
        exit(1);
    }
    printf("listening successful.\n");
    
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
            if (FD_ISSET(i, &read_fds)) { // we got one!!
                if (i == listener) {
                    // handle new connections
                    int addrlen = sizeof(remoteaddr);
                    int newfd; // newly accept()ed socket descriptor
                    if ((newfd = accept(listener, &remoteaddr, &addrlen)) == -1)
                        printf("accept failed");
                    else {
                        FD_SET(newfd, &master);             // add to master set
                        if (newfd > fdmax) fdmax = newfd;   // keep track of the maximum
                        printf("selectserver: new connection from %s on "
                        "socket %d\n", inet_ntoa(remoteaddr.sin_addr), newfd);
                    }
                }
                else {
                    int nbytes; char buf[256]; // buffer for client data
                    // handle data from a client
                    if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0) {
                        // got error or connection closed by client
                        if (nbytes == 0) // connection closed
                            printf("selectserver: socket %d hung up\n", i);
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