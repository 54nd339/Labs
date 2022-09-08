#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = ntohs(8000);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("Enter a String: ");
	char msg[1000]; gets(msg);
	
	int m = sendto(sockfd, msg, sizeof(msg), 0,
		(struct sockaddr *)&servaddr, sizeof(struct sockaddr));
	if (m == -1) {
		printf("Sending Failed.");
		exit(1);
	}
	else
		printf("Message Sent : %s\n", msg);

	char buf[100];
	int len = sizeof(servaddr);
	int n = recvfrom(sockfd, buf, 100, 0, (struct sockaddr *)&servaddr, &len);
	if (n == -1) {
        printf("Receiving Failed");
        exit(1);
    }
    else {
        buf[n] = '\0';
		for (int i = 0; buf[i] != '\0'; i++) {
			if(buf[i] >= 'a' && buf[i] <= 'z') {
				buf[i] = buf[i] - 32;
			}
		}
		printf("String in Uppercase : %s \n",buf);
    }

	close (sockfd);
	return 0;
}