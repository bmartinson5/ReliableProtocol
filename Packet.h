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
    virtual void serialize() {};
    virtual void deserialize(char *) {};

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

    void deserializer(void* copyTo, char * toCopy, int sizeT)
    {
        memcpy(copyTo, toCopy+offset, sizeT);
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

    Connection(int pktL, string file) : Packet('S', sizeof(int) + pktL+1), ptkLength(pktL+1)
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
    ConnectionReply(): Packet('R'){};
    ConnectionReply(long fileS): Packet('R', sizeof(long)), fileSize(fileS) { serialize(); };
    void serialize() override;
    void deserialize(char *) override;
    long FileSize() { return fileSize;};
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
    DataPacket(int num, int ptkL, char *d): Packet('D', sizeof(int)*2+ptkL), seqNum(num), pktLength(ptkL)
    {
        data = new char[pktLength];
        memcpy(data, d, pktLength);
        serialize();
    };

    ~DataPacket()
    {
        delete [] data;
    }

    void serialize() override;
    void deserialize(char *) override;
    int PktLength(){ return pktLength;}
    char* Data() { return data; }
    int Seqnum() { return seqNum; }

};

class DataReply : public Packet
{
private:
    int seqNum;
public:
    DataReply(): Packet('A') {};
    DataReply(int num): Packet('A', sizeof(int)), seqNum(num) { serialize(); }
    void serialize() override;
    void deserialize(char *) override;
    int Seqnum() { return seqNum; }
};

class CloseConnection : public Packet
{
private:
    int seqNum;
public:
    CloseConnection(int num): Packet('C', sizeof(int)), seqNum(num) {};
    void serialize() override;
    void deserialize(char *) override;

};


#endif //RELIABLEPROTOCOL_PACKET_H
