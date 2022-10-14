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
    struct sockaddr_in addr, client;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(1);
    }
    printf("Bind successful.\n");

    int reqNo = 0;
    // revceive window size
    int len = sizeof(client); int windowSize;
    recvfrom(sock, &windowSize, sizeof(windowSize), 0, (struct sockaddr *)&client, &len);
    while(1) {
        pkt p;
        // receive packet in window
        for(int i = 0; i < windowSize; i++) {
            recvfrom(sock, &p, sizeof(p), 0, (struct sockaddr *)&client, &len);
            printf("\nReceived packet %d: %s\n", p.seqNo, p.msg);
            int reqNo = (p.seqNo + 1) % windowSize;
        }        

        printf("Sending ACK %d\n", reqNo);
        printf("Do you want to send ack? (y/n): ");
        char ch; scanf("%c", &ch);
        if (ch == 'n') continue;
        else {
            printf("Do you want to alter ack? (y/n): ");
            scanf("%c", &ch);
            if (ch == 'y') {
                printf("Enter new ack: ");
                scanf("%d", &reqNo);
            }
        }
        sendto(sock, &reqNo, sizeof(reqNo), 0, (struct sockaddr *)&client, len);
 
        printf("Sent ACK %d\n", reqNo);
        if (strcmp(p.msg, "exit") == 0 && ch == 'n') break;
    }
    // Close the socket
    close(sock);
    return 0;
}