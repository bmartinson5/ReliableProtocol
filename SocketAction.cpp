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




