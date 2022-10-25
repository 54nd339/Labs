#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define LENGTH 2048

int flag = 0;
char name[32];
void catch_ctrl_c_and_exit(int sig) {
    flag = 1;
}

void send_msg_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[LENGTH] = {};
    char buffer[LENGTH + 32] = {};
    while (1) {
        // printf("Enter your message: ");
        fgets(message, LENGTH, stdin);
        if(strcmp(message, "exit") == 0) break;

        sprintf(buffer, "%s: %s", name, message);
        if(send(sockfd, buffer, strlen(buffer), 0) < 0 ) {
            perror("Sending message failed");
            break;
        }
        else
            printf("You : %s\n", message);

        memset(message, 0, LENGTH);
        memset(buffer, 0, LENGTH + 32);
    }
    catch_ctrl_c_and_exit(2);
}

void recv_msg_handler(void *arg) {
    int sockfd = *((int *)arg);
    char message[LENGTH+32] = {}; int n;
    while ((n = recv(sockfd, message, LENGTH, 0)) > 0) {
        message[n] = '\0';
        printf("%s", message);
    }
    if (n < 0) {
        perror("Receiving message failed");
        exit(1);
    }
    else {
        printf("Server closed connection\n");
        exit(1);
    }
}

int main() {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket creation failed...\n");
        exit(0);
    }
    printf("Socket successfully created..\n");

    // fill server information
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    printf("connected to the server..\n");

    // get name
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);
    signal(SIGINT, catch_ctrl_c_and_exit);
    
    // send name
    if(send(sockfd, name, 32, 0) == -1) {
        printf("Failed to send name.\n");
        exit(0);
    }
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