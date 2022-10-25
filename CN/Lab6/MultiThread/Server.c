#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 2048

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
static _Atomic unsigned int cli_count = 0;
static int uid = 10;

// client structure
struct client_t {
    struct sockaddr_in address;
    int sockfd, uid;
    char name[32];
} *clients[MAX_CLIENTS];

// add client to queue
void queue_add(struct client_t *cl) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (!clients[i]) {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// remove client from queue
void queue_remove(int uid) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i]) {
            if (clients[i]->uid == uid) {
                clients[i] = NULL;
                break;
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// send message to all clients except sender
void send_message(char *s, int uid) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i]) {
            if (clients[i]->uid != uid) {
                if(send(clients[i]->sockfd, s, strlen(s), 0) < 0 ) {
                    perror("Sending message failed");
                    break;
                }
                else
                    printf("Message sent to client at address %s:%d\n",
                    inet_ntoa(clients[i]->address.sin_addr), ntohs(clients[i]->address.sin_port));
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// handle all communication with the client
void *handle_client(void *arg) {
    char buff_out[BUFFER_SIZE], name[32];
    int leave_flag = 0; cli_count++;
    struct client_t *cli = (struct client_t *)arg;

    // name
    if (recv(cli->sockfd, name, 32, 0) <= 0 || strlen(name) >= 32 - 1) {
        printf("Didn't enter the name.\n");
        leave_flag = 1;
    } else {
        strcpy(cli->name, name);
        sprintf(buff_out, "%s has joined\n", cli->name);
        printf("%s", buff_out);
        send_message(buff_out, cli->uid);
    }
    bzero(buff_out, BUFFER_SIZE);
    
    while (1) {
        if (leave_flag) break;
        int receive = recv(cli->sockfd, buff_out, BUFFER_SIZE, 0);
        if (receive > 0) {
            if (strlen(buff_out) > 0) {
                send_message(buff_out, cli->uid);
                printf("%s -> %s\n", buff_out, cli->name);
            }
        } else if (receive == 0 || strcmp(buff_out, "exit") == 0) {
            sprintf(buff_out, "%s has left\n", cli->name);
            printf("%s", buff_out);
            send_message(buff_out, cli->uid);
            leave_flag = 1;
        } else {
            printf("Recieving Failed\n");
            leave_flag = 1;
        }
        bzero(buff_out, BUFFER_SIZE);
    }

    // delete client from queue and yield thread
    close(cli->sockfd);
    queue_remove(cli->uid);
    free(cli); cli_count--;
    pthread_detach(pthread_self());
    return NULL;
}

int main() {
    // socket create and varification
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    // fill server information
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // bind the socket
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    int option = 1;
    signal(SIGPIPE, SIG_IGN);
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&option, sizeof(option)) < 0){
		perror("ERROR: setsockopt failed");
        return EXIT_FAILURE;
	}

    // Accept the data packet from client and verification
    int len = sizeof(cliaddr);
    pthread_t thread_id;
    while(1){
        int new_socket = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (new_socket < 0) {
            printf("server acccept failed...\n");
            exit(0);
        }
        else
            printf("server acccept the client...\n");

        // check if max clients is reached
        if (cli_count + 1 == MAX_CLIENTS) {
            printf("Max clients reached. Rejected: ");
            printf("%s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            close(new_socket);
            continue;
        }

        // client settings
        struct client_t *cli = (struct client_t *)malloc(sizeof(struct client_t));
        cli->address = cliaddr;
        cli->sockfd = new_socket;
        cli->uid = uid++;

        // add client to the queue and fork thread
        queue_add(cli);
        pthread_create(&thread_id, NULL, &handle_client, (void *)cli);
    }

    // After chatting close the socket
    close(sockfd);
    return 0;
}