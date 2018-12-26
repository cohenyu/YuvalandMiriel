//
// Created by yuval on 19/12/18.
//

#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include "SocketCommunication.h"
#define BUFFER_SIZE 1024


/*
 * this is the constructor of the SocketCommunication.
 */
SocketCommunication::SocketCommunication() {
}

/**
 * The function read from the given socket until the given separator and returns what it reads.
 * @param socket the socket to read from
 * @param separator read until the separator
 * @return what the function read from the socket
 */
string SocketCommunication::readFromSocket(int socket, char separator) {
//    char buffer[256];
//    int n;
//
//
//    /* Now read server response */
//    bzero(buffer,256);
//    n = read(socket, buffer, 255);
//
//    if (n < 0) {
//        perror("ERROR reading from socket");
//        exit(1);
//    }
//    string data;
//    string str(buffer);
//    return str;
    char c = '\0';
    int n;
    string data;

    if (socket < 0){
        perror("ERROR socket not found");
    }

    n = read(socket, &c, 1);
    while (c != separator) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        data += c;
        n = read(socket, &c, 1);
    }

    return data;
}

/**
 * The function write the string data to the the given socket.
 * @param socket the socket to write to
 * @param data the string to write
 */
void SocketCommunication::writeToSocket(int socket, string data) {
    //הגודל של הבאפר היה 256 .שיניתי אותו אם לא עובד שנדע שזה בגלל זה .אם עובד למחוק הערה
    int n;
    char buffer[BUFFER_SIZE];
    bzero(buffer,BUFFER_SIZE);
    strcpy(buffer, data.c_str());
    //fgets(buffer,255,stdin);

    /* Send message to the server */
    n = write(socket, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

//    int n;
//
//    if (socket < 0){
//        perror("ERROR socket not found");
//    }
//    // todo
//    char buffer[256];
//    bzero(buffer,256);
//    strcpy(buffer,data.c_str());
//    n = write(socket, buffer, strlen(buffer));
//    //n = ::send(socket, data.c_str(), strlen((char*) data.c_str()), 0);
//
//    cout<<data<<endl;
//
//    //n = write(socket, data.c_str(), data.length());
//    if (n < 0) {
//        perror("ERROR writing to socket");
//        exit(1);
//    }
}
