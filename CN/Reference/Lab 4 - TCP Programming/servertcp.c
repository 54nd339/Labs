#include <stdio.h>

#include <string.h>

#include <unistd.h>

#include <stdlib.h>

//#include <sys/socket.h>

//#include <arpa/inet.h>



int main(void)

{

    int sockfd, client_sock, client_size;

    struct sockaddr_in servaddr, cliaddr;

    char server_message[2000], client_message[2000];



    // Clean buffers:

    memset(server_message, '\0', sizeof(server_message));

    memset(client_message, '\0', sizeof(client_message));



    // Create socket:

    sockfd = socket(AF_INET, SOCK_STREAM, 0);



    if(sockfd < 0){

        printf("Socket Creation FAILED!!\n");

        return -1;

    }

    printf("Socket created successfully\n");



    // Set port and IP:

    servaddr.sin_family = AF_INET;

    servaddr.sin_port = htons(2000);

    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");



    // Bind to the set port and IP:

    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0){

        printf("Bind Failed!!\n");

        return -1;

    }

    printf("Bind Successfull!!\n");



    // Listen for clients:

    if(listen(sockfd, 1) < 0){

        printf("Error, Couldnt Listen !!\n");

        return -1;

    }

    printf("\nListening for incoming client messages.....\n");



    // Accept an incoming connection:

    client_size = sizeof(cliaddr);

    client_sock = accept(sockfd, (struct sockaddr*)&cliaddr, &client_size);



    if (client_sock < 0){

        printf("Can't accept the message\n");

        return -1;

    }

    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));



    // Receive client's message:

    if (recv(client_sock, client_message, sizeof(client_message), 0) < 0){

        printf("Couldn't receive messages!!\n");

        return -1;

    }

    printf("Message from client: %s\n", client_message);



    // Respond to client:

    strcpy(server_message, "Hellu Client.");



    if (send(client_sock, server_message, strlen(server_message), 0) < 0){

        printf("Can't send\n");

        return -1;

    }



    // Closing the socket:

    close(client_sock);

    close(sockfd);



    return 0;

}
