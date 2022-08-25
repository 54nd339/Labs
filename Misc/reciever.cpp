#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080
using namespace std;

int main() {		
	// Creating socket file descriptor
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		cerr << "Socket creation failed" << endl;
		exit(EXIT_FAILURE);
	}
    else
        cout << "Socket created successfully." << endl;
		
	// Filling server information
	struct sockaddr_in recvaddr, sendaddr;
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = PORT;
	recvaddr.sin_addr.s_addr = INADDR_ANY;
		
	// Bind the socket with the port
	if (bind(sockfd, (const struct sockaddr *)&recvaddr, sizeof(recvaddr)) == -1) {
		cerr << "Binding Failed." << endl;
		exit(EXIT_FAILURE);
	}
    else 
        cout << "Binding successful." << endl;
	
    // Receiving message from Sender
	char buffer[100];
	int len = sizeof(sendaddr);
	int n = recvfrom(sockfd, (char *)buffer, 100, 0,
        (struct sockaddr *)&sendaddr, (socklen_t *)&len);
    if (n == -1) {
        cerr << "Receiving Failed" << endl;
        exit(EXIT_FAILURE);
    }
    else
        cout << "Sender : " << buffer << endl;

    // Sending message to Sender
    cout << "Enter Message : ";
	string msg; cin >> msg;
	int m = sendto(sockfd, &msg, sizeof(msg), 0,
        (const struct sockaddr *) &sendaddr, len);
    if (m == -1) {
        cerr << "Sending Failed." << endl;
        exit(EXIT_FAILURE);
    }
    else 
	    cout << "Message sent. : " << msg << endl;
		
	return 0;
}