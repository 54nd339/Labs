#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>>
#define PORT 8080
typedef struct PKT {
    int seqNo;
    char msg[100];
}pkt;

int main() {	
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket Creation FAILED.\n");
		exit(1);
	}
    printf("Socket created successfully.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = in_addr("127.0.0.1");
	
    int flag; pkt packet;
    for(int seqNo = 1; 1; seqNo++) {
        // Sending packet
        if(flag != seqNo) {
            printf("Enter Message : ");
            scanf("%s", packet.msg);
            packet.seqNo = seqNo % 2;
            flag = seqNo;
        }

        int m = sendto(sockfd, &packet, sizeof(packet), 0,
            (struct sockaddr *) &recvaddr, sizeof(recvaddr));
        if (m == -1) {
            printf("Failed to send message.\n");
            exit(1);
        }
        printf("Sent Packet Message : %s\n", packet.msg);
        printf("Sent packet Sequence No. : %d\n", packet.seqNo);

        // Receiving an ack
        int ack;
        int len, n = recvfrom(sockfd, &ack, sizeof(ack), 0,
            (struct sockaddr *) &recvaddr, &len);
        if (n == -1) {
            printf("Failed to receive ack.\n");
            packet.seqNo--;
        }

        printf("Received ack: %d\n", ack);
    }
	return 0;
}