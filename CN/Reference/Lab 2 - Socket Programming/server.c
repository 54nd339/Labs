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
	char *hello = "Hello From Server";
	struct sockaddr_in servaddr, cliaddr;

	//Creating socket file descriptor
	if (sockfd = socket(AF_INET, SOCK_DGRAM,0) < 0){
			perror("Socket Creation Failed");
		exit(EXIT_FAILURE);
	}
	memset (&servaddr, 0 , sizeof(servaddr));
	memset (&cliaddr, 0 , sizeof(cliaddr));
	
	//Filling Server Information
	servaddr.sin_family = AF_INET; //IPV4
	servaddr.sin_addr.s_addr = INADDR_ANY; //inet_aton("")
	servaddr.sin_port = htons(PORT);

	//Bind the socket with the server address
	if(bind(sockfd,(const struct sockaddr *)&servaddr,sizeof(servaddr))<0){
		perror("Bind Failed");
		exit(EXIT_FAILURE);
	}
	int len,n;
	len = sizeof(cliaddr); //len is value/resuit
	
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) 		&cliaddr,&len);
	buffer[n] = '\0';
	printf("Client : %s\n",buffer);

	sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,(const struct 		sockaddr *) &cliaddr, len);
	
	printf("Hello Message Sent.\n");
	
	return 0;
}