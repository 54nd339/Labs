#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "queue.h"

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

    pkt p; int seqNo;
    printf("Enter m : ");
    int m; scanf("%d", &m);
    int windowSize = (int)pow(2, m);
    queue *q = init(windowSize);
    int base = 0, nextSeqNo = 0;
    
    // send the window size
    sendto(sock, &windowSize, sizeof(windowSize), 0, (struct sockaddr *)&addr, sizeof(addr));
    printf("Sent window size: %d\n", windowSize);

    // Sender side loop for go back n protocol
    while(1) {
        // Send packets in window
        while (nextSeqNo < base + windowSize) { // Send packets in window
            printf("\nEnter message: ");
            scanf("%[^\n]%*c", p.msg);
            p.seqNo = nextSeqNo;
            enqueue(q, p); 
            // Send the packet
            printf("Sending packet %d: %s\n", p.seqNo, p.msg);
            sendto(sock, &p, sizeof(p), 0, (struct sockaddr *)&addr, sizeof(addr));
            printf("Sent packet %d: %s\n", p.seqNo, p.msg);
            nextSeqNo++;
        }

        // Receive the ack
        int len = sizeof(addr); int ack;
        recvfrom(sock, &ack, sizeof(ack), 0, (struct sockaddr *)&addr, &len);
        printf("Received ACK %d\n", ack);
        if (ack > base && ack < nextSeqNo) {
            while(base < ack) {
                dequeue(q);
                base++;
            }
            // sendinng remaining packets
            printf("Sending remaining packets\n");
            for (int i = q->front; i <= q->rear; i++) {
                p = q->arr[i];
                printf("Sending packet %d: %s\n", p.seqNo, p.msg);
                sendto(sock, &p, sizeof(p), 0, (struct sockaddr *)&addr, sizeof(addr));
                printf("Sent packet %d: %s\n", p.seqNo, p.msg);
            }            
        } else {
            printf("Invalid ACK\n");
        }
    }

    // Close the socket
    close(sock);
    return 0;
}