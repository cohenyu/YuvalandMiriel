////
//// Created by yuval on 19/12/18.
////
//
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>

#include "TCPClient.h"

TCPClient::TCPClient(string ipAddress, int port) {
    this->ipAddress = ipAddress;
    this->port = port;
    this->clientSocket = -1;
}

void TCPClient::connectToServer() {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (this->clientSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(this->ipAddress.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(this->port);

    /* Now connect to the server */
    if (connect(this->clientSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}

string TCPClient::readFromServer(char seperator) {
    return socketCommunication.readFromSocket(this->clientSocket,seperator);
}

void TCPClient::writeToServer(string data) {
    socketCommunication.writeToSocket(this->clientSocket, data);
}
