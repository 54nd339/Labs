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

    int flag = 1; // 1 for sending 0 for not sending
    pkt p; int seqNo;
    do {
        printf("Enter initial seqNo (0/1): ");
        scanf("%d", &seqNo);
    } while (seqNo != 0 && seqNo != 1);

    while(1) {
        if (flag) {
            printf("\nEnter a message: ");
            scanf("%[^\n]%*c", p.msg);
            p.seqNo = seqNo;
            printf("Sending packet %d: %s\n", p.seqNo, p.msg);
        }
        if(sendto(sockfd, &p, sizeof(p), 0, (struct sockaddr *)&recvaddr, sizeof(recvaddr)) < 0){
            printf("Sending Failed. Resending...\n");
            continue;
        }
        printf("Sent packet with seqNo %d and message %s\n", p.seqNo, p.msg);
        printf("Waiting for ACK %d\n", !seqNo);

        // receive the ack
        int len = sizeof(recvaddr); int ack;
        int n = recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&recvaddr, &len);
        if(n < 0){
            printf("Receiving Failed.\n");
            exit(1);
        }
        printf("Received ACK %d\n", ack);
        flag = ack != seqNo;
        
        if (flag) {
            printf("ACK %d received. Packet %d sent successfully.\n", ack, seqNo);
            seqNo = !seqNo;
            if (strcmp(p.msg, "exit") == 0) break;
        } else {
            printf("ACK %d received. Packet %d not sent successfully.\n", ack, seqNo);\
            printf("\nResending packet %d: %s\n", p.seqNo, p.msg);
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}