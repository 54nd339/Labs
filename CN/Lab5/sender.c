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
	struct sockaddr_in recvaddr;
	recvaddr.sin_family = AF_INET;
    recvaddr.sin_port = htons(PORT);
    recvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ack; pkt p;
    int seqNo = 0, flag = 1;
    while(1) {
        if(flag) {
            printf("Enter a message: ");
            scanf("%[^\n]%*c", p.msg);
            p.seqNo = seqNo;
        }
        if (sendto(sockfd, &p, sizeof(p), 0,
        (struct sockaddr *)&recvaddr, sizeof(recvaddr)) < 0) {
            printf("Sending Failed.\n");
            exit(1);
        }
        printf("Sent packet with seqNo %d and message %s\n", p.seqNo, p.msg);
        if (strcmp(p.msg, "exit") == 0) break;

        int len, n = recvfrom(sockfd, &ack, sizeof(ack), 0,
            (struct sockaddr *)&recvaddr, &len);
        if(n < 0) {
            printf("Receiving Failed.\n");
            exit(1);
        }
        printf("Received ack : %d\n", ack);

        flag = ack != seqNo;
        if (flag)
            seqNo = (seqNo+1) % 2;
    }

    // Close the socket
    close(sockfd);
    return 0;
}