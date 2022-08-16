#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080

int main() {	
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
		exit(1);
	}
    else
        printf("Socket created successfully.\n");
		
	// Filling server information
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;

    // Sending msgessage to reciever
	printf("Enter 2 nos. : ");
    for(int i = 0; i < 2; i++) {
        int a; scanf("%d",&a);
        int m = sendto(sockfd, &a, sizeof(int), 0,
            (const struct sockaddr *) &recvaddr, sizeof(recvaddr));
        if (m == -1) {
            printf("Sending Failed.");
            exit(1);
        }
        else
            printf("INT Sent : %d\n", a);
    }
	
    // Receiving message from reciever
	int res, len, n = recvfrom(sockfd, &res, sizeof(int), 0,
        (struct sockaddr *) &recvaddr, &len);
	if (n == -1) {
        printf("Recieving Failed");
        exit(1);
    }
    else
        printf("Result Recieved : %d\n", res);
	
	close(sockfd);
	return 0;
}