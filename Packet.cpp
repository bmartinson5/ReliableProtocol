//
// Created by Benjamin Martinson on 1/18/19.
//

#include "Packet.h"
#include <iostream>
#include <string>
#include <stdio.h>



void Connection::deserialize(char * ptk)
{
    deserializer(&type, ptk, sizeof(char));
    deserializer(&ptkLength, ptk, sizeof(int));
    deserializer(&fileName, ptk, ptkLength);

}

void Connection::serialize()
{
    serializer<char>(type);
    serializer<int>(ptkLength);
    serializer<string>(fileName, ptkLength);
}

void ConnectionReply::deserialize(char * ptk)
{
    deserializer(&type, ptk, sizeof(char));
    deserializer(&fileSize, ptk, sizeof(long));
    cout << "fileseive  = " << fileSize << endl;

}

void ConnectionReply::serialize()
{
    serializer<char>(type);
    serializer<long>(fileSize);
}

void DataPacket::deserialize(char * ptk)
{
    deserializer(&type, ptk, sizeof(char));
    deserializer(&seqNum, ptk, sizeof(int));
    deserializer(&pktLength, ptk, sizeof(int));
    data = new char[pktLength];
    memcpy(data, ptk+offset, pktLength);

}

void DataPacket::serialize()
{
    serializer<char>(type);
    serializer<int>(seqNum);
    serializer<int>(pktLength);
    memcpy(pack+offset, data,pktLength);
}

void DataReply::deserialize(char * ptk)
{
    deserializer(&type, ptk, sizeof(char));
    deserializer(&seqNum, ptk, sizeof(int));
}

void DataReply::serialize()
{
    serializer<char>(type);
    serializer<int>(seqNum);
    cout << "seqnum = " << seqNum << endl;
}

void CloseConnection::deserialize(char * ptk)
{
    deserializer(&type, ptk, sizeof(char));
    deserializer(&seqNum, ptk, sizeof(int));
}

void CloseConnection::serialize()
{
    serializer<char>(type);
    serializer<int>(seqNum);
}

void ReplyAck::deserialize(char * ptk)
{
    type = *ptk;
}

void ReplyAck::serialize()
{
    serializer<char>(type);

}

