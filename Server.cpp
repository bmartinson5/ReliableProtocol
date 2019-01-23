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


int establishConnection(int sockId, struct sockaddr_in cli_addr)
{
    char reply[256];
    //listen for clients initial connection
    receiveMessage(sockId, cli_addr, reply);

    //Reply that connection has been made
//    Connection connectionPacket(5, {"hello"});
//    sendMessage<Connection>(connectionPacket, cli_addr, sockId);
    return 0;
}



int main(int argc, char *argv[])
{

    //setup socket
    int sockId, newsockId, port, n;
    struct sockaddr_in serv_addr, cli_addr;
    port = atoi(argv[2]);

    //open socket
    sockId = socket(AF_INET, SOCK_DGRAM, 0);
    checkError(sockId, "Error Opening Socket");

    createAddress(serv_addr, port);

    //bind to port
    int status = ::bind(sockId, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    checkError(status, "Error Binding");
    cout << endl << "Server running on port: " << argv[2] << endl;

    //start listening for client
    establishConnection(sockId, cli_addr);

    //start sending data



    close(sockId);
    return 0;


    return 0;
}