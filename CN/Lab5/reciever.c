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

    pkt p; int ack;
    while(1) {
        int len, n = recvfrom(sock, &p, sizeof(p), 0, (struct sockaddr *)&client, &len);
        if (n < 0) {
            perror("recvfrom failed");
            exit(1);
        }
        printf("Received packet with seqNo %d and message %s\n", p.seqNo, p.msg);
        if (strcmp(p.msg, "exit") == 0) {
            break;
        }
        ack = (p.seqNo+1) % 2;
        while (sendto(sock, &ack, sizeof(ack), 0, (struct sockaddr *)&client, sizeof(client)) < 0) {
            perror("sendto failed");
            exit(1);
        }
        printf("Sent ack : %d\n", ack);
    }
    // Close the socket
    close(sock);
    return 0;
}