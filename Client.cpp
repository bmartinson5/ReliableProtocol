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


int establishConnection(string fileName, struct sockaddr_in &serv_addr, int serverSocket)
{
    //error handling is done by calls to sendMessage and recieveMessage

    cout << endl << "\n...Client establishing connection with server...\n\n";
    //create first connection packet and send it to the server
    Connection connectionPacket(fileName.length(), fileName);
    sendMessage(connectionPacket, serv_addr, serverSocket, sizeof(serv_addr));

    //wait for Connection Reply packet
    ConnectionReply connectionReply;
    receiveMessage(connectionReply, serverSocket, serv_addr);

    //send the Reply ACK
    ReplyAck replyAck;
    sendMessage(replyAck, serv_addr, serverSocket, sizeof(serv_addr));

    return connectionReply.FileSize();
}

void writePacketDataToFile(ofstream &file, int length, char * data, int &offset)
{
    length = length;
    file.write(data, length);
    offset += length;
}


void receiveFile(struct sockaddr_in &serv_addr, int serverSocket, long fileSize)
{
    ofstream file2("output2.jpg", ios::binary);

    int count = 0;
    int offset = 0;
    while(offset < fileSize - 1)
    {
        DataPacket data;
        receiveMessage(data, serverSocket, serv_addr);
        ++count;

        int packetNum = data.Seqnum();
        if(packetNum == count)
        {
            //send dataReply
            DataReply dataReply(count);
            sendMessage(dataReply, serv_addr, serverSocket, sizeof(serv_addr));
        }
        else
        {
            cout << "wrong packet" << endl;
            count = data.Seqnum();
        }
        //cout << "Recieved Packet. Type = " << data.Type() << endl;

        writePacketDataToFile(file2, data.PktLength(), data.Data(), offset);
    }

    file2.close();
}


void closeConnection(struct sockaddr_in &serv_addr, int socket)
{
    CloseConnection closeConnection(100);
    sendMessage(closeConnection, serv_addr, socket, sizeof(serv_addr));
    close(socket);
}

int main(int argc, char *argv[])
{
    //setup socket
    struct sockaddr_in serv_addr;
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    checkError((serverSocket < 0), "Error Opening Socket");

    //setup addresses
    int port = atoi(argv[2]);
    createAddress(serv_addr, port);

    //connect with server
    long fileSize = establishConnection(argv[3], serv_addr, serverSocket);
    //check if connected; fileSize != 0
    checkError((fileSize <= 0), "Client could not connect with Server", "Client has connected with server");

    //start recieving file
    receiveFile(serv_addr, serverSocket, fileSize);

    closeConnection(serv_addr, serverSocket);
    return 0;
}



