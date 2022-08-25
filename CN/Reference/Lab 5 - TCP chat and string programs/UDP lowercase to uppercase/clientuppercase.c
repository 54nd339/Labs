#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>

int main()
  {
    int cs,bs;
    cs=socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in x;
    x.sin_family=AF_INET;
    x.sin_port=ntohs(8006);
    x.sin_addr.s_addr=inet_addr("127.0.0.1");
   
    char msg[1000];
    printf("Enter a String: ");
    gets(msg);

    char buf[100];
    int len=sizeof(x);
   
    sendto(cs,msg,sizeof(msg),0,(struct sockaddr *) &x,sizeof(struct sockaddr));
    recvfrom(cs,buf,100,0,(struct sockaddr *)&x,&len);
    for (int i = 0; buf[i]!='\0'; i++) {
      if(buf[i] >= 'a' && buf[i] <= 'z') {
         buf[i] = buf[i] - 32;
      }
   }
    printf("String in Uppercase : %s \n",buf);
    close (cs);
    }
