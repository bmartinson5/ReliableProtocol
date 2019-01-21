//
// Created by Benjamin Martinson on 1/19/19.
//

#include "Packet.h"
#include "SocketAction.h"

#include <pthread.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

struct sockaddr_in serv_addr;
const int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

int establishConnection(string fileName)
{
    Connection connectionPacket(fileName.length(), fileName);
    sendMessage<Connection>(connectionPacket, serv_addr, serverSocket);

    char reply[256];
    receiveMessage(serverSocket, serv_addr, reply);
}



int main(int argc, char *argv[])
{

    checkError(serverSocket, "Error Opening Socket");

    int port = atoi(argv[2]);
    createAddress(serv_addr, port);

    establishConnection(argv[3]);

    close(serverSocket);
    return 0;
}



