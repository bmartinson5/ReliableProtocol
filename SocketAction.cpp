//
// Created by Benjamin Martinson on 1/20/19.
//

#include "SocketAction.h"
#include <strings.h>
#include <string>
#include <iostream>
using namespace std;

void createAddress(struct sockaddr_in &addr, const int port)
{
    bzero((char *) &addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void createAddress2(struct sockaddr_in &addr, const int port)
{
    bzero((char *) &addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = ntohs(port);
    addr.sin_addr.s_addr = ntohl(INADDR_ANY);
}

int receiveMessage(Packet & ptk, const int sockId, struct sockaddr_in &addr)
{
    socklen_t len = sizeof(struct sockaddr_in);
    char temp[2000];
    int n = ::recvfrom(sockId, temp, 2000, MSG_WAITALL, (struct sockaddr *) &addr, &len);
    checkError((n<0), "Error Recieving Message");
    ptk.deserialize(temp);

    cout << "Received packet. Type: " << ptk.Type() << endl;
    return len;
}

int sendMessage(Packet &ptk, const struct sockaddr_in &addr, int serverSocket, int len)
{
    int status = ::sendto(serverSocket, ptk.SerialPacket(), ptk.Size(), 0, (const struct sockaddr *) &addr, len);
    checkError((status < 0), "Error Sending Message");
    cout << "Message sent. Type: " << ptk.Type() << endl;
    return 0;
}



int checkError(bool condition, const string errorMessage, string message)
{
    if(condition)
    {
        cout << errorMessage << endl;
        exit(1);
    }
    else
    {
        if(message != "") message += '\n';
        cout << message;
    }
    return 0;
}




