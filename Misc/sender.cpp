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
	struct sockaddr_in recvaddr;
    recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = INADDR_ANY;

    // Sending message to receiver
    cout << "Enter Message : ";
	string msg; cin >> msg;
	int m = sendto(sockfd, &msg, sizeof(msg), 0,
        (const struct sockaddr *) &recvaddr, sizeof(recvaddr));
	if (m == -1) {
        cerr << "Sending Failed.";
        exit(EXIT_FAILURE);
    }
    else
	    cout << "Message sent. : " << msg << endl;
	
    // Receiving message from receiver
	char buffer[100];
	int len, n = recvfrom(sockfd, (char *)buffer, 100, 0,
        (struct sockaddr *)&recvaddr, (socklen_t *)&len);
	if (n == -1) {
        cerr << "Receiving Failed";
        exit(EXIT_FAILURE);
    }
    else 
        cout << "Reciever : " << buffer << endl;
	
	close(sockfd);
	return 0;
}