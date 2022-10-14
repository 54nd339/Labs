#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct PKT {
    int seqNo;
    char msg[100];
}pkt;

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }
    printf("Socket creation successful.\n");

    // Fill the server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int flag = 1; // 1 for sending 0 for not sending
    pkt p; int seqNo;
    do {
        printf("Enter initial seqNo (0/1): ");
        scanf("%d", &seqNo);
    } while (seqNo != 0 && seqNo != 1);

    while(1) {
        if (flag) {
            printf("\nEnter message: ");
            scanf(" %[^\n]", p.msg);
            p.seqNo = seqNo;
            printf("Sending packet %d: %s\n", p.seqNo, p.msg);
        }
        sendto(sock, &p, sizeof(p), 0, (struct sockaddr *)&addr, sizeof(addr));
        printf("Sent packet %d: %s\n", p.seqNo, p.msg);
        printf("Waiting for ACK %d\n", !seqNo);

        // receive the ack
        int len = sizeof(addr); int ack;
        recvfrom(sock, &ack, sizeof(ack), 0, (struct sockaddr *)&addr, &len);
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
    close(sock);
    return 0;
}