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

int main(int argc, char *argv[])
{

    char buffer[256];
    int serverSocket, newServerSocket, port, n;
    struct sockaddr_in serv_addr, cli_addr;
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(serverSocket < 0)
    {
        cout << "error opening socket" << endl;
        return 1;
    }

    port = atoi(argv[2]);
    createAddress(serv_addr, port);

    int status = ::bind(serverSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if(status < 0)
    {
        cout << "error binding address" << endl;
    }

    cout << endl << "Server running on port: " << port << endl;

    char * packet;
    socklen_t len;
    int recieved = ::recvfrom(serverSocket, (char *) buffer, 256, MSG_WAITALL, (struct sockaddr *) &cli_addr, &len);
    buffer[recieved] = '\0';

    cout << "Server received packet: " << buffer << endl;

    close(serverSocket);
    return 0;


    return 0;
}