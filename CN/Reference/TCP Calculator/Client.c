#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    else
        printf("Socket created successfully\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed!!\n");
        exit(1);
    }
    printf("Connection with server Processed Successfully !!\n");

    printf("Enter operation :\n + : Addition \n - : Subtraction \n / : Division \n * : Multiplication \n");
    char operator; scanf("%c",&operator);
    int op1, op2, result;
    printf("Enter operands : ");
    scanf("%d %d", &op1, &op2);

    write(sockfd, &operator, 10);
    write(sockfd, &op1, sizeof(op1));
    write(sockfd, &op2, sizeof(op2));
    read(sockfd, &result, sizeof(result)); 
    printf("Operation result from server : %d\n", result);  
    close(sockfd);
    return 0;
}