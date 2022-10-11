#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 8080
typedef struct PKT {
    int seqNo;
    char msg[100];
}pkt;

int main() {		
	// Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
		exit(1);
	}
    printf("Socket created successfully.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr, sendaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		
	// Bind the socket with the port
	if (bind(sockfd, (const struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		printf("Binding Failed");
		exit(1);
	}
    printf("Binding successful.\n");
	
    pkt packet; int flag = 1;
    while(1) {
        // Recieving Packet
        int len, n = recvfrom(sockfd, &packet, sizeof(packet), 0,
            (struct sockaddr *)&sendaddr, &len);
        if (n == -1) {
            printf("Failed to receive packet.\n");
        }
        printf("Packet msg recieved: %s\n",packet.msg);
        printf("Packet seq No. recieved: %d\n", packet.seqNo);

        // Sending ack
        int ack = (packet.seqNo + 1) % 2;
        if(ack != flag) {
            flag = ack;
            int m = sendto(sockfd, &ack, sizeof(ack), 0,
                (struct sockaddr *)&sendaddr, len);
            while (m == -1) {
                printf("Sending Ack Failed.");
                flag = ack ? 0 : 1;
            }
        }
        printf("Ack sent : %d\n", ack);
        if(strcmp(packet.msg, "exit") == 0) break;
    }
	return 0;
}