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

    while(1) {
        int len = sizeof(client); pkt p;
        int stat = recvfrom(sock, &p, sizeof(p), 0, (struct sockaddr *)&client, &len);
        if(stat < 0) {
            perror("recvfrom failed");
            exit(1);
        }
        printf("\nReceived packet %d: %s\n", p.seqNo, p.msg);
        int ack = p.seqNo == 0;

        printf("Sending ACK %d\n", ack);
        printf("Do you want to alter ack? (y/n): ");
        char ch; scanf(" %c", &ch);
        if (ch == 'y') ack = !ack;

        stat = sendto(sock, &ack, sizeof(ack), 0, (struct sockaddr *)&client, len);
        if(stat < 0) {
            perror("sendto failed");
            exit(1);
        }
        printf("Sent ACK %d\n", ack);
        if (strcmp(p.msg, "exit") == 0 && ch == 'n') break;
    }
    // Close the socket
    close(sock);
    return 0;
}