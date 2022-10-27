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
#define MAX 10

pthread_mutex_t cli_mutex = PTHREAD_MUTEX_INITIALIZER;
static _Atomic unsigned int cnt = 0;
static int uid = 10;

// client structure
struct client_t {
    struct sockaddr_in address;
    int sockfd, uid;
    char name[32];
} *clients[MAX];

// add client to queue
void enqueue(struct client_t *cl) {
    pthread_mutex_lock(&cli_mutex);
    for (int i = 0; i < MAX; ++i) {
        if(!clients[i]) {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&cli_mutex);
}

// remove client from queue
void dequeue(int uid) {
    pthread_mutex_lock(&cli_mutex);
    for(int i = 0; i < MAX; ++i) {
        if(clients[i]) {
            if(clients[i]->uid == uid) {
                clients[i] = NULL;
                break;
            }
        }
    }
    pthread_mutex_unlock(&cli_mutex);
}

// send message to all clients except sender
void sendMsg(char *msg, int uid) {
    pthread_mutex_lock(&cli_mutex);
    for(int i = 0; i < MAX; ++i) {
        if(clients[i]) {
            if(clients[i]->uid != uid) {
                if(send(clients[i]->sockfd, msg, strlen(msg), 0) < 0 ) {
                    printf("Sending Failed."); break;
                }
                printf("Message sent to client at %s:%d\n",
                inet_ntoa(clients[i]->address.sin_addr), ntohs(clients[i]->address.sin_port));
            }
        }
    }
    pthread_mutex_unlock(&cli_mutex);
}

// handle all communication with the client
void *handleClient(void *arg) {
    char buff[SIZE], name[32];
    int flag = 0; cnt++;
    struct client_t *cli = (struct client_t *)arg;

    // name
    if(recv(cli->sockfd, name, 32, 0) <= 0 || strlen(name) >= 32 - 1) {
        printf("Didn't enter the name.\n");
        flag = 1;
    }
    else {
        strcpy(cli->name, name);
        sprintf(buff, "%s has joined\n", cli->name);
        printf("\n%s", buff); sendMsg(buff, cli->uid);
    }
    bzero(buff, SIZE);
    
    while(1) {
        if(flag) break;
        int receive = recv(cli->sockfd, buff, SIZE, 0);
        if(receive > 0) {
            if(strlen(buff) > 0) {
                printf("\n%s", buff);
                sendMsg(buff, cli->uid);
            }
        }
        else if(receive == 0 || strcmp(buff, "exit") == 0) {
            sprintf(buff, "%s has left\n", cli->name);
            printf("\n%s", buff); sendMsg(buff, cli->uid);
            flag = 1;
        }
        else {
            printf("Recieving Failed.\n");
            flag = 1;
        }
        bzero(buff, SIZE);
    }

    // delete client from queue and yield thread
    close(cli->sockfd);
    dequeue(cli->uid);
    free(cli); cnt--;
    pthread_detach(pthread_self());
    return NULL;
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation Failed.\n");
        exit(1);
    }
    printf("Socket Creation Successful.\n");

    // Set port and IP:
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind to the set port and IP:
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("Port Binding Failed.\n");
        exit(1);
    }
    printf("Bind Successfull with PORT: %d\n", PORT);

    // Listen for clients:
    if(listen(sockfd, 1) < 0){
        printf("Server Listening Failed.\n");
        exit(1);
    }
    printf("\nServer Listening..\n");

    // Set listener socket to allow multiple connections
    int option = 1;
    signal(SIGPIPE, SIG_IGN);
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&option, sizeof(option)) < 0){
		perror("ERROR: setsockopt failed");
        exit(1);
	}

    int len = sizeof(cliaddr);
    pthread_t cli_thread;
    while(1){
        // Accept client:
        int newSock = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if(newSock < 0)
            printf("Error Accepting Client\n");
        else {
            printf("Client connected from %s:%i\n",
            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            printf("Total Clients: %d\n", cnt+1);
        }

        // Reject if max clients is reached:
        if(cnt + 1 == MAX) {
            printf("Max clients reached. Rejected: ");
            printf("%s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            close(newSock);
            continue;
        }

        struct client_t *cli = (struct client_t *)malloc(sizeof(struct client_t));
        cli->address = cliaddr;
        cli->sockfd = newSock;
        cli->uid = uid++;

        enqueue(cli);
        pthread_create(&cli_thread, NULL, &handleClient, (void *)cli);
    }

    // Close the socket:
    close(sockfd);
    return 0;
}