#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define SIZE 2048

int flag = 0;
char name[32];
void ctrl_c(int sig) {
    flag = 1;
}

void send_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[SIZE] = {};
    char buffer[SIZE + 32] = {};
    while (1) {
        // printf("Enter your message: ");
        fgets(message, SIZE, stdin);
        if(strcmp(message, "exit\n") == 0) break;

        sprintf(buffer, "%s: %s", name, message);
        if(send(sockfd, buffer, strlen(buffer), 0) < 0 ) {
            printf("Sending Failed");
            break;
        }
        printf("You: %s", message);

        bzero(message, SIZE);
        bzero(buffer, (SIZE + 32));
    }
    flag = 1;
}

void recv_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[SIZE+32] = {}; int n;
    while ((n = recv(sockfd, message, SIZE, 0)) > 0) {
        message[n] = '\0';
        printf("\n%s", message);
    }
    if(n < 0) {
        perror("Receiving Failed");
        exit(1);
    }
    printf("Server Connection Closed\n");
    exit(1);
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation Failed.\n");
        exit(1);
    }
    printf("Socket Creation Successful.\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection Failed.\n");
        exit(1);
    }
    printf("Connection Established with Server.\nEnter 'exit' to leave\n");

    signal(SIGINT, ctrl_c);
    // Setting up the name:
    printf("\nEnter Your Name: ");
    scanf("%[^\n]%*c", name);
    if(send(sockfd, name, 32, 0) < 0) {
        printf("Sending Name Failed.\n");
        exit(1);
    }
    printf("Name Sent Successfully.\n");

    // Creating thread to handle sending message:
    pthread_t send_thread;
    if(pthread_create(&send_thread, NULL, (void *)send_handler, &sockfd) != 0) {
        printf("Failed to Create Send Thread.\n");
        exit(1);
    }
    printf("Send Thread Creation successful.\n");

    // Creating thread to handle receiving message:
    pthread_t recv_thread;
    if(pthread_create(&recv_thread, NULL, (void *)recv_handler, &sockfd) != 0) {
        printf("Failed to create Receive thread.\n");
        exit(1);
    }
    printf("Receive Thread Creation Successful.\n");

    // Waiting for threads to finish:
    while (1) {
        if(flag) {
            printf("See Yaa Soon..\n");
            break;
        }
    }

    // Close the socket:
    close(sockfd);
    return 0;
}