// Write the client side and server side program TCP using C to design a Calculator (Menu driven), where the
// Client sends two integers and an option as an operator (+, -, *, / or ℅) to the Server,
// Server calculates accordingly and returns the //result to the Client. Now Client will display the result. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    else
        printf("Socket created successfully\n");

    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Bind Failed!!\n");
        exit(1);
    }
    else
        printf("Bind Successfull!!\n");

    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Error, Couldnt Listen !!\n");
        exit(1);
    }
    else
        printf("\nListening for incoming client messages.....\n");

    // Accept an incoming connection:
    int client_size = sizeof(cliaddr);
    int connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &client_size);

    if (connfd < 0){
        printf("Can't accept the message\n");
        exit(1);
    }
    else
        printf("Client connected at IP: %s and port: %i\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
    
    char operator; int op1, op2, result;
    read(connfd, &operator, 10);
    read(connfd, &op1, sizeof(op1));
    read(connfd, &op2, sizeof(op2));
    if(operator == '+')
        result = op1 + op2;
    else if(operator == '-')
        result = op1 - op2;
    else if(operator == '*')
        result = op1 * op2;
    else if(operator == '/')
        result = op1 / op2;
    else 
        printf("ERROR: Unsupported Operation");

    printf("Result is: %d %c %d = %d\n",op1, operator, op2, result);
    write(connfd, &result, sizeof(result));   
    close(sockfd);
    return 0;
}