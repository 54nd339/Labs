#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 9034
#define LENGTH 2048

int flag = 0;
char name[32];
void catch_ctrl_c_and_exit(int sig) {
    flag = 1;
}

void recv_msg_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[LENGTH+32] = {}; int n;
    while ((n = recv(sockfd, message, LENGTH, 0)) > 0) {
        message[n] = '\0';
        printf("%s", message);
    }
    if (n < 0)
        perror("Receiving message failed");
    else
        printf("Server closed connection\n");
    exit(1);
}

void send_msg_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[LENGTH] = {};
    char buffer[LENGTH + 32] = {};
    while (1) {
        // printf("Enter your message: ");
        scanf("%[^\n]%*c", message);
        if(strcmp(message, "exit") == 0) break;

        sprintf(buffer, "%s: %s\n", name, message);
        if(send(sockfd, buffer, strlen(buffer), 0) < 0 ) {
            perror("Sending message failed");
            break;
        }
        printf("You : %s\n", message);

        memset(message, 0, LENGTH);
        memset(buffer, 0, LENGTH + 32);
    }
    catch_ctrl_c_and_exit(2);
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED.\n");
        exit(1);
    }
    printf("Socket created successfully.\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed.\n");
        exit(1);
    }
    printf("Connection Established with Server.\n");
    
    // get name
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);
    signal(SIGINT, catch_ctrl_c_and_exit);
    
    // send name
    char buffer[LENGTH + 32] = {};
    sprintf(buffer, "%s joined the chat..\n", name);
    if(send(sockfd, buffer, LENGTH + 32, 0) == -1) {
        printf("Failed to send name.\n");
        exit(0);
    }
    else
        printf("Name sent successfully.\n");

    // create a thread to send message
    pthread_t send_msg_thread;
    if(pthread_create(&send_msg_thread, NULL, (void *)send_msg_handler, &sockfd) != 0) {
        printf("Failed to create thread.\n");
        exit(0);
    }
    else
        printf("Send thread created successfully.\n");

    // create a thread to receive message
    pthread_t recv_msg_thread;
    if(pthread_create(&recv_msg_thread, NULL, (void *)recv_msg_handler, &sockfd) != 0) {
        printf("Failed to create thread.\n");
        exit(0);
    }
    else
        printf("Receive thread created successfully.\n");

    printf("\nEnter 'exit' to leave the chatroom.\n");

    while (1) {
        if(flag) {
            printf("Bye\n");
            break;
        }
    }

    // close the socket
    close(sockfd);
    return 0;
}