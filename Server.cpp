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



int checkFile(string fileName, long &fileSize)
{
    ifstream file("/Users/benjaminmartinson/CLionProjects/ReliableProtocol/test.jpg", ios::binary);

    if(!file)
    {
        cout << "Could not open file specified." << endl;
        return 0;
    }
    //retrieve file size
    file.seekg(0, file.end);
    fileSize = file.tellg();

    file.close();
    return 1;
}


bool readDataAndSend(int sockId, struct  sockaddr_in &cli_addr, string fileName, int len, long fileSize)
{
    ifstream file("/Users/benjaminmartinson/CLionProjects/ReliableProtocol/test.jpg", ios::binary);

    char entireFile[fileSize];
    file.read(entireFile, fileSize);

    int count = 0;
    int offset = 0;

    int packetSize = 1024;
    while(offset < fileSize)
    {
        //send packet of size 'packetSize' until remainder of file is less than that
        packetSize = min(packetSize, (int)(fileSize-offset));
        char packetData[packetSize];
        memcpy(&packetData, entireFile+offset, packetSize);

        DataPacket dataPacket(++count, packetSize, packetData);
        sendMessage(dataPacket, cli_addr, sockId, len);
        offset += packetSize;

        DataReply dataReply;
        receiveMessage(dataReply, sockId, cli_addr);

        if(count !=  dataReply.Seqnum())
        {
            cout << "Wrong number packet...." << dataReply.Seqnum() << endl;
        }

    }
    //close connection
    CloseConnection closeConnection(19);
    sendMessage(closeConnection, cli_addr, sockId, len);

    file.close();
    return true;
}


int establishConnection(int sockId, struct sockaddr_in &cli_addr, string &fileName, long &fileSize, int &len)
{
    //listen for clients initial connection
    Connection connectionPacket;
    len = receiveMessage(connectionPacket, sockId, cli_addr);

    fileName = connectionPacket.FileName();
    if(connectionPacket.Type() != 'S' || !checkFile(fileName, fileSize))
        return 0;



    //Reply that connection has been made
    ConnectionReply connectionReply(fileSize);
    sendMessage(connectionReply, cli_addr, sockId, len);

    ReplyAck replyAck;
    receiveMessage(replyAck, sockId, cli_addr);
    if(replyAck.Type() != 'W')
        return 0;

    //else connection was established
    return 1;
}

void closeConnection(struct sockaddr_in &cli_addr, int socket)
{
    CloseConnection closeConnection(100);
    receiveMessage(closeConnection, socket, cli_addr);
    close(socket);
}


int main(int argc, char *argv[])
{
    string fileName = "";
    long fileSize = 0;

    //setup socket
    int sockId, newsockId, port, n;
    struct sockaddr_in serv_addr, cli_addr;
    port = atoi(argv[2]);
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    //open socket
    sockId = socket(AF_INET, SOCK_DGRAM, 0);
    checkError((sockId < 0), "Error Opening Socket");

    createAddress2(serv_addr, port);

    //bind to port
    int status = ::bind(sockId, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    checkError((status < 0), "Error Binding");
    cout << endl << "Server running on port: " << argv[2] << endl;

    //start listening for client
    int len = 0;
    int result = establishConnection(sockId, cli_addr, fileName, fileSize, len);
    checkError(result == 0, "Server could not connect with client", "Server has connected with a client");

    //start sending file data
    readDataAndSend(sockId, cli_addr, fileName, len, fileSize);
    //close connection
    closeConnection(cli_addr, sockId);
    return 0;

}