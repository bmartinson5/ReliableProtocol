//
// Created by Benjamin Martinson on 1/18/19.
//

#ifndef RELIABLEPROTOCOL_PACKET_H
#define RELIABLEPROTOCOL_PACKET_H

#import <string>
#import <vector>
#include <iostream>

using namespace std;

class Packet {
protected:
    char type; //type of packet, identifier
    int offset = 0; //used to create serial pack
    int size;   //size of serialized packet
    char *pack; //the serialized packet

public:
    Packet(char type) : type(type){};
    Packet(char type, int extraSize) : type(type), offset(0)
    {
        size = sizeof(char) + extraSize;
        pack = new char[size];
    };

    //getters
    char* Type() { return &type; };
    int Size() {return size;};
    char* SerialPacket() {return pack;};

    //virtual function
    virtual void serialize() = 0;

    //template functions that couldn't be in Packet.cpp
    template <typename T>
    void serializer(T toCopy, int &off)
    {
        int size = sizeof(T);
        memcpy(pack+off, &toCopy, size);
        off += size;
    }

    template <typename T>
    void serializer(T toCopy, int &off, int size)
    {
        memcpy(pack+off, &toCopy, size);
        off += size;
    }

};

class Connection: public Packet {
private:
    string fileName;
    int ptkLength;

public:
    Connection(int ptkL, string file) : Packet('S', sizeof(int) + file.length()), fileName(file), ptkLength(file.length())
    {
        serialize();
    };

    void serialize() override;
};

//class ConnectionReply: public Packet
//{
//private:
//    long fileSize;
//public:
//    ConnectionReply(int fileS): Packet('R'), fileSize(fileS) {};
//    char* serialize() override;
//};

//class ReplyAck : public Packet
//{
//public:
//    ReplyAck(): Packet('W') {};
//    char * serialize() override;
//
//};
//
//
//class DataPacket : public Packet
//{
//private:
//    int seqNum;
//    int pktLength;
//    vector<char> data;
//
//public:
//    DataPacket(int num, int ptkL): Packet('D'), seqNum(num), pktLength(ptkL) {};
//    char* serialize() override;
//
//};
//
//class DataReply : public Packet
//{
//private:
//    int seqNum;
//public:
//    DataReply(int num): Packet('A'), seqNum(num) {};
//    char* serialize() override;
//};
//
//class CloseConnection : public Packet
//{
//private:
//    int seqNum;
//public:
//    CloseConnection(int num): Packet('C'), seqNum(num) {};
//    char* serialize() override;
//
//};


#endif //RELIABLEPROTOCOL_PACKET_H
