//
// Created by Benjamin Martinson on 1/20/19.
//

#ifndef RELIABLEPROTOCOL_SOCKETACTION_H
#define RELIABLEPROTOCOL_SOCKETACTION_H

#include <iostream>
#include <netdb.h>
using namespace std;

void createAddress(struct sockaddr_in &addr, int port);

template <typename T>
int sendMessage(T &ptk, struct sockaddr_in &addr, int serverSocket)
{
    char *packet = ptk.serialize();
    int ptkLen = ptk.Size(packet);
    cout << "Sending to port: " << addr.sin_port << endl;
    int status = ::sendto(serverSocket, packet, ptkLen, 0, (const struct sockaddr *) &addr, sizeof(addr));
    if(status < 0)
    {
        cout << "Error sending message" << endl;
        return 1;
    }
    else
    {
        cout << "Message sent" << endl;
        return 0;
    }
}

#endif //RELIABLEPROTOCOL_SOCKETACTION_H
