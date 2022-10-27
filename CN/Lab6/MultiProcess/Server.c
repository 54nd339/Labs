#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

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
	
    int len = sizeof(cliaddr), cnt = 0;
	while (1) {
        // Accept client:
        int newSock = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
        if(newSock < 0) {
            printf("Error Accepting Client\n");
            exit(1);
        }
		printf("Client connected from %s:%i\n",
        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        printf("Total Clients: %d\n", cnt);

		if(fork() == 0) {
            while (1) {
                // Receive client's message:
                char buff[SIZE];
                int n = recv(newSock, buff, sizeof(buff), 0);
                if(n < 0) {
                    printf("Receiving Failed.\n");
                    exit(1);
                }

                buff[n] = '\0';
                printf("Client: %s\n", buff);
                if(strcmp(buff, "exit") == 0) {
                    send(newSock, "Bye", strlen("Bye"), 0);
                    printf("Client disconnected from %s:%d\n",
                    inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    close(newSock); break;
                }

                // Respond to client:
                printf("Response: ");
                if(send(newSock, buff, strlen(buff), 0) < 0) {
                    printf("Sending Failed.\n");
                    exit(1);
                }
                printf("%s echoed\n", buff);
            }
		}
	}

    // Close the socket:
	close(sockfd);
	return 0;
}