//
// Created by Benjamin Martinson on 1/18/19.
//

#include "Packet.h"
#include <iostream>


//to_string doesn't automatically overload string
string to_string(const string& value)
{
    return value;
}

template <typename T>
void serializer(char* p, T toCopyInt, int &off)
{
    int size = to_string(toCopyInt).length();
    char const * toC = to_string(toCopyInt).c_str();
    memcpy(p+off, toC, sizeof(char)*size);
    off += size;
}

int Packet::Size(char * packet)
{
    int count = 0;
    while(packet[count] != '\0')
        ++count;
    return count;
}

char* Connection::serialize()
{
    char *p = new char[sizeof(char) + sizeof(int) + sizeof(char)*fileName.length()];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    serializer<int>(p, ptkLength, offset);
    serializer<string>(p, fileName, offset);
    return p;
}

char* ConnectionReply::serialize()
{
    char *p = new char[sizeof(char) + sizeof(long)];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    serializer<long>(p, fileSize, offset);
    return p;
}

char* DataPacket::serialize()
{
    char *p = new char[sizeof(char) + sizeof(long)];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    serializer<int>(p, seqNum, offset);
    serializer<int>(p, pktLength, offset);
    //also need raw data
    return p;
}

char* DataReply::serialize()
{
    char *p = new char[sizeof(char) + sizeof(int)];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    serializer<int>(p, seqNum, offset);
    return p;
}

char* CloseConnection::serialize()
{
    char *p = new char[sizeof(char) + sizeof(int)];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    serializer<int>(p, seqNum, offset);
    return p;
}
char* ReplyAck::serialize()
{
    char *p = new char[sizeof(char)];
    int offset = 0;
    serializer<string>(p, string(1,type), offset);
    return p;

}

