//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SOCKETCOMMUNICATION_H
#define YUVALANDMIRIEL_SOCKETCOMMUNICATION_H

#include <string>

using namespace std;

class SocketCommunication {
public:
    SocketCommunication();
    string readLineFromSocket(int socket);
    void writeToSocket(int socket, string data);

};


#endif //YUVALANDMIRIEL_SOCKETCOMMUNICATION_H