#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main (){
	int sockfd;
	char buffer [MAXLINE];
	char *hello = "Hello From Client";
	struct sockaddr_in servaddr , cliaddr;

	//Creating socket file descriptor
	if (sockfd = socket(AF_INET, SOCK_DGRAM,0) < 0){
			perror("Socket Creation Failed");
		exit(EXIT_FAILURE);
	}
	memset (&servaddr, 0 , sizeof(servaddr));
	
	
	//Filling Server Information
	servaddr.sin_family = AF_INET; //IPV4
	servaddr.sin_addr.s_addr = INADDR_ANY; //inet_aton("")
	servaddr.sin_port = htons(PORT);

	
	int len,n;
	len = sizeof(cliaddr); //len is value/resuit

	sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,(const struct 		sockaddr *) &servaddr, sizeof(servaddr));

	printf("Hello Message Sent !!\n");	
	
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) 		&servaddr,&len);

	buffer[n] = '\0';
	printf("Server : %s\n",buffer);

	
	close(sockfd);
	
	return 0;
}