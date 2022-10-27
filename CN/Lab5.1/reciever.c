#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

typedef struct PKT {
    int seqNo;
    char msg[SIZE];
}pkt;

int main() {
    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket Creation Failed.\n");
		exit(1);
	}
    printf("Socket Creation Successful.\n");

	// Filling server information
	struct sockaddr_in recvaddr, sendaddr;
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind the socket with the port
	if (bind(sockfd, (const struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		printf("Port Binding Failed.");
		exit(1);
	}
    printf("Binding Successful with PORT: %d\n", PORT);

    while(1) {
        int len = sizeof(sendaddr); pkt p;
        int n = recvfrom(sockfd, &p, sizeof(p), 0, (struct sockaddr *)&sendaddr, &len);
        if (n == -1) {
            printf("Receiving Failed.\n");
            exit(1);
        }
        printf("\nReceived packet %d: %s\n", p.seqNo, p.msg);
        int ack = p.seqNo == 0;

        printf("Sending ACK %d\n", ack);
        printf("Do you want to alter ack? (y/n): ");
        char ch; scanf(" %c", &ch);
        if (ch == 'y') ack = !ack;

        if(sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&sendaddr, len) < 0) {
            printf("Sending Failed.");
            exit(1);
        }
        printf("Sent ACK %d\n", ack);
        if (strcmp(p.msg, "exit") == 0 && ch == 'n')
            break;
    }

    // Close the socket
    close(sockfd);
    return 0;
}