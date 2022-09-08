// Write UDP client server program where client sends a lowercase string to the server.
// The server then sends back the string converted into uppercase.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() { 
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
		exit(1);
	}
	else
		printf("Socket created successfully.\n");

	// Filling server information
	struct sockaddr_in servaddr, cliaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = ntohs(8000);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Bind the socket with the port
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		printf("Binding Failed");
		exit(1);
	}
	else 
		printf("Binding successful.\n");

	char buf[100];
	int len = sizeof(cliaddr);
	int n = recvfrom(sockfd, buf, 100, 0, 
		(struct sockaddr *)&cliaddr, &len);
	if (n == -1) {
		printf("Receiving Failed");
		exit(1);
	}
	else {
		buf[n] = '\0';
		printf("Server : %s\n", buf);
	}

	for (int i = 0; buf[i] != '\0'; i++) {
		if(buf[i] >= 'A' && buf[i] <= 'Z') {
			buf[i] = buf[i] + 32;
		}
	}
	printf("String entered by Client : %s \n",buf);

	int m = sendto(sockfd, buf, sizeof(buf), 0,
		(struct sockaddr *) &cliaddr, sizeof(struct sockaddr));
    if (m == -1) {
        printf("Sending Failed.");
        exit(1);
    }
    else 
	    printf("Hello message sent.\n");

	return 0;
}