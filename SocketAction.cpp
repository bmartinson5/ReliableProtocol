//
// Created by Benjamin Martinson on 1/20/19.
//

#include "SocketAction.h"
#include <strings.h>
#include <iostream>
using namespace std;

void createAddress(struct sockaddr_in &addr, int port)
{
    bzero((char *) &addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

char * receiveMessage(int sockId, struct sockaddr_in &addr, char buffer[])
{
    socklen_t len;
    int n = ::recvfrom(sockId, (char *) buffer, 256, MSG_WAITALL, (struct sockaddr *) &addr, &len);
    buffer[n] = '\0';
    cout << "Received packet: " << buffer << endl;
    return buffer;
}

int checkError(int value, string message)
{
    if(value < 0)
    {
        cout << message << endl;
        exit(1);
    }
    return 0;
}

//sendMessage is in header file because it is a template function




