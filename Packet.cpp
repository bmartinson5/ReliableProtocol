//
// Created by Benjamin Martinson on 1/18/19.
//

#include "Packet.h"
#include <iostream>
#include <string>

void Connection::deserialize(char * ptk)
{
    type = *ptk;
    ptkLength = *(ptk+sizeof(char));
    fileName = (ptk+sizeof(char)+sizeof(int));
}

void Connection::serialize()
{
    serializer<char>(type);
    serializer<int>(ptkLength);
    serializer<string>(fileName, ptkLength);
}

void ConnectionReply::deserialize(char * ptk)
{
    type = *ptk;
    fileSize = *(ptk+1);
}

void ConnectionReply::serialize()
{
    serializer<char>(type);
    serializer<long>(fileSize);
}

void DataPacket::deserialize(char * ptk)
{
    type = *ptk;
    seqNum = *(ptk+1);
    pktLength = *(ptk+1+ sizeof(int));
    data = (ptk+1+ sizeof(int)+sizeof(int));
}

void DataPacket::serialize()
{
    serializer<char>(type);
    serializer<int>(seqNum);
    serializer<int>(pktLength);
    serializer<string>(data, pktLength);
    //cout << "packet = " << (pack + 9) << endl;
    //also need data
}

void DataReply::deserialize(char * ptk)
{
    type = *ptk;
    seqNum = *(ptk+1);
}

void DataReply::serialize()
{
    serializer<char>(type);
    serializer<int>(seqNum);
}

void CloseConnection::deserialize(char * ptk)
{
    type = *ptk;
    seqNum = *(ptk+1);
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

