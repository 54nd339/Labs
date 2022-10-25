#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 4444

int main() {
	// Create socket:
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		printf("Error in connection.\n");
		exit(1);
	}
    printf("Server Socket is created.\n");

	// Set port and IP the same as server-side:
    struct sockaddr_in server_addr, cli_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind the socket to the port and IP:
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error in binding.\n");
        exit(1);
    }
    printf("Bind to port %d\n", PORT);

    // Listen for connections:
	if (listen(sockfd, 10) == 0) {
		printf("Listening...\n\n");
	}
	
    int cnt = 0, clientSocket;
    int len = sizeof(cli_addr);
	while (1) {
        clientSocket = accept(sockfd, (struct sockaddr*)&cli_addr, &len);
        if (clientSocket < 0) {
            printf("Error in connection.\n");
            exit(1);
        }
		printf("Connection accepted from %s:%d\n",
        inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
		printf("Clients connected: %d\n", ++cnt);

		if (fork() == 0) {
            char buff[2000];
            while (1) {
                // Receive the client's message:
                int n = recv(clientSocket, buff, sizeof(buff), 0);
                if (n < 0) {
                    printf("Error in receiving.\n");
                    exit(1);
                }
                buff[n] = '\0';
                printf("Client: %s\n", buff);
                if (strcmp(buff, "exit") == 0) {
                    printf("Client disconnected.\n");
                    break;
                }

                // Send the message to the client:
                printf("Server: ");
                if (send(clientSocket, buff, strlen(buff), 0) < 0) {
                    printf("Error in sending.\n");
                    exit(1);
                }
                if (strcmp(buff, "exit") == 0) {
                    printf("Client disconnected from %s:%d\n",
                    inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    break;
                }
            }
		}
	}

	// Close the client socket id
	close(clientSocket);
	return 0;
}