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


bool establishConnection(string fileName, struct sockaddr_in &serv_addr, int serverSocket)
{
    cout << endl << "\n...Client establishing connection with server...\n\n";
    //create first connection packet and send it to the server
    Connection connectionPacket(fileName.length(), fileName);
    sendMessage(connectionPacket, serv_addr, serverSocket, sizeof(serv_addr));

    //wait for Connection Reply packet
    ConnectionReply connectionReply(1000);
    receiveMessage(connectionReply, serverSocket, serv_addr);

    //send the Reply ACK
    ReplyAck replyAck;
    sendMessage(replyAck, serv_addr, serverSocket, sizeof(serv_addr));


    return true;
}

void receiveFile(struct sockaddr_in &serv_addr, int serverSocket)
{
    int count = 0;
    char type = 'Q';
    do
    {
        DataPacket data;
        receiveMessage(data, serverSocket, serv_addr);
        type = data.Type();
        cout << "Recieved data count = " << ++count << endl;
    } while(type != 'S');
}

int main(int argc, char *argv[])
{
    struct sockaddr_in serv_addr;
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    checkError(serverSocket, "Error Opening Socket");

    int port = atoi(argv[2]);
    createAddress(serv_addr, port);

    if(establishConnection(argv[3], serv_addr, serverSocket))
        cout << "\nClient has connected with server at port: " << port << endl;
    else
    {
        cout << "\nClient could not connect with server! Socket closed at port: " << port << endl;
        close(serverSocket);
    }

    receiveFile(serv_addr, serverSocket);

    close(serverSocket);
    return 0;
}



