// Write UDP client server program where client sends a lowercase string to the server. The server then sends back the string converted into uppercase.

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>

int main()
{ 
	  int ss,sb;
	  ss=socket(AF_INET,SOCK_DGRAM,0);

	  struct sockaddr_in servaddr,clientaddr;
	  servaddr.sin_family=AF_INET;
	  servaddr.sin_port=ntohs(8006);
    	  servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    sb=bind(ss,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));


    char buf[100];
    int len=sizeof(struct sockaddr);
    
	
    recvfrom(ss,buf,100,0,(struct sockaddr *)&clientaddr,&len);
    for (int i = 0; buf[i]!='\0'; i++) {
      if(buf[i] >= 'A' && buf[i] <= 'Z') {
         buf[i] = buf[i] + 32;
      }
   }
    printf("String entered by Client : %s \n",buf);

    sendto(ss,buf,sizeof(buf),0,(struct sockaddr *) &clientaddr,sizeof(struct sockaddr));

}
