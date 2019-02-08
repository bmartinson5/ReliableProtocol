//
// Created by Benjamin Martinson on 1/18/19.
//

#ifndef RELIABLEPROTOCOL_PACKET_H
#define RELIABLEPROTOCOL_PACKET_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Packet {
protected:
    char type; //type of packet, identifier
    int offset = 0; //used to create serial pack
    int size;   //size of serialized packet
    char *pack = NULL; //the serialized packet
    //char *dsPack; //the deserialized packet

public:
    Packet() {};

    Packet(char type) : type(type), size(sizeof(char))  //for packets with just a type, length of 1
    {
        pack = new char[sizeof(char)];
    };
    Packet(char type, int extraSize) : type(type)
    {
        size = sizeof(char) + extraSize;
        pack = new char[size];
    };

    //getters, setters
    const char Type() { return type; };
    const int Size() {return size;};
    const char* SerialPacket() {return pack;};

    //virtual function
    virtual void serialize() = 0;
    virtual void deserialize(char *) = 0;

    //

    //template functions that couldn't be in Packet.cpp
    template <typename T>
    void serializer(T toCopy)
    {
        int sizeT = sizeof(T);
        memcpy(pack+offset, &toCopy, sizeT);
        offset += sizeT;
    }

    template <typename T>
    void serializer(T toCopy, int sizeT)
    {
        memcpy(pack+offset, &toCopy, sizeT);
        offset += sizeT;
    }


    ~Packet()
    {
        if(pack)
            delete []pack;
    }

};

class Connection: public Packet {
private:
    string fileName;
    int ptkLength;

public:
    Connection() : Packet (){};

    Connection(int ptkL, string file) : Packet('S', sizeof(int) + file.length()+1), ptkLength(file.length()+1)
    {
        fileName.assign(file);
        serialize();
    };

    string FileName() {return fileName;};
    void serialize() override;
    void deserialize(char *) override;
};

class ConnectionReply: public Packet
{
private:
    long fileSize;
public:
    ConnectionReply(long fileS): Packet('R', sizeof(long)), fileSize(fileS) { serialize(); };
    void serialize() override;
    void deserialize(char *) override;
};

class ReplyAck : public Packet
{
public:
    ReplyAck(): Packet('W') { serialize(); };
    void serialize() override;
    void deserialize(char *) override;

};


class DataPacket : public Packet
{
private:
    int seqNum;
    int pktLength;
    char* data;

public:
    DataPacket(): Packet('D'){};
    DataPacket(int num, int ptkL, char *d): Packet('D', sizeof(int)*2+ptkL), seqNum(num), pktLength(ptkL), data(d)
    {
        serialize();
    };
    void serialize() override;
    void deserialize(char *) override;

};

class DataReply : public Packet
{
private:
    int seqNum;
public:
    DataReply(int num): Packet('A'), seqNum(num) {};
    void serialize() override;
    void deserialize(char *) override;
};

class CloseConnection : public Packet
{
private:
    int seqNum;
public:
    CloseConnection(int num): Packet('C'), seqNum(num) {};
    void serialize() override;
    void deserialize(char *) override;

};


#endif //RELIABLEPROTOCOL_PACKET_H
