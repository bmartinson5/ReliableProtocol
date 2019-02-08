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
#include <fstream>
#include <stdexcept>



bool checkFile(string fileName)
{
    ifstream file("/Users/benjaminmartinson/CLionProjects/ReliableProtocol/test.jpg", ios::binary);

    if(!file)
    {
        cout << "Could not open file specified." << endl;
        return false;
    }
    file.close();
    return true;
}


bool readDataAndSend(int sockId, struct  sockaddr_in &cli_addr, string fileName, int len)
{
    ifstream file("/Users/benjaminmartinson/CLionProjects/ReliableProtocol/test.jpg", ios::binary);
    //ifstream file("/Users/benjaminmartinson/CLionProjects/ReliableProtocol/test.txt", ios::binary);
    char buffer[1024];

    int count = 0;
    while(file.read(buffer, sizeof(buffer)))
    {
        DataPacket dataPacket(count, sizeof(buffer), buffer);
        sendMessage(dataPacket, cli_addr, sockId, len);

    }
    file.close();
    return true;
}


int establishConnection(int sockId, struct sockaddr_in &cli_addr, string &fileName)
{
    //listen for clients initial connection
    Connection connectionPacket;
    int len = receiveMessage(connectionPacket, sockId, cli_addr);

    fileName = connectionPacket.FileName();
    if(connectionPacket.Type() != 'S' || !checkFile(fileName))
        return 0;



    //Reply that connection has been made
    ConnectionReply connectionReply(1000);
    sendMessage(connectionReply, cli_addr, sockId, len);

    ReplyAck replyAck;
    receiveMessage(replyAck, sockId, cli_addr);
    if(replyAck.Type() != 'W')
        return 0;

    //else connection was established
    return len;
}


int main(int argc, char *argv[])
{

    //setup socket
    int sockId, newsockId, port, n;
    struct sockaddr_in serv_addr, cli_addr;
    port = atoi(argv[2]);
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    //open socket
    sockId = socket(AF_INET, SOCK_DGRAM, 0);
    checkError(sockId, "Error Opening Socket");

    createAddress2(serv_addr, port);

    //bind to port
    int status = ::bind(sockId, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    checkError(status, "Error Binding");
    cout << endl << "Server running on port: " << argv[2] << endl;

    //start listening for client
    string fileName = "";
    int len = establishConnection(sockId, cli_addr, fileName);
    if(fileName != "")
        cout << "\nServer has connected with client " << port << endl;
    else
    {
        cout << "\nServer could not connect with client! Socket closed at port: " << port << endl;
        close(sockId);
        return 1;
    }


    //start sending file data
    readDataAndSend(sockId, cli_addr, fileName, len);


    //start sending data



    close(sockId);
    return 0;


    return 0;
}