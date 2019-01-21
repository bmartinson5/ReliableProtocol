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

//struct sockaddr_in &createAddress(struct sockaddr_in addr, int port)

int main(int argc, char *argv[])
{
    struct sockaddr_in serv_addr;
    int port = atoi(argv[2]);

    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(serverSocket< 0)
    {
        cout << "error opening socket" << endl;
        return 1;
    }

    createAddress(serv_addr, port);

    string fileName = argv[3];
    Connection connectionPacket(fileName.length(), fileName);
    sendMessage<Connection>(connectionPacket, serv_addr, serverSocket);

    close(serverSocket);
    return 0;


    return 0;
}



