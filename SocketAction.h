//
// Created by Benjamin Martinson on 1/20/19.
//

#ifndef RELIABLEPROTOCOL_SOCKETACTION_H
#define RELIABLEPROTOCOL_SOCKETACTION_H

#include <iostream>
#include <netdb.h>

#include "Packet.h"
using namespace std;

void createAddress(struct sockaddr_in &addr, const int port);
void createAddress2(struct sockaddr_in &addr, const int port);
int receiveMessage(Packet &, const int sockId, struct sockaddr_in &addr);
int checkError(const int, const string);
int sendMessage(Packet&, const struct sockaddr_in&, const int serverSocket, int);



#endif //RELIABLEPROTOCOL_SOCKETACTION_H
