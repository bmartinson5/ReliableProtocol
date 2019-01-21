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
    char type;

public:
    Packet(char type) : type(type){};

    char* Type() { return &type; };
    virtual char* serialize(){ return &type; };



};

class Connection: public Packet {
private:
    int ptkLength;
    string fileName;


public:
    Connection(int ptkL, string file) : Packet('S'), ptkLength(ptkL), fileName(file) { };

    char* serialize() override;
};

class ConnectionReply: public Packet
{
private:
    long fileSize;
public:
    ConnectionReply(int fileS): Packet('R'), fileSize(fileS) {};
    char* serialize() override;
};

class ReplyAck : public Packet
{
public:
    ReplyAck(): Packet('W') {};
    char * serialize() override;

};


class DataPacket : public Packet
{
private:
    int seqNum;
    int pktLength;
    vector<char> data;

public:
    DataPacket(int num, int ptkL): Packet('D'), seqNum(num), pktLength(ptkL) {};
    char* serialize() override;

};

class DataReply : public Packet
{
private:
    int seqNum;
public:
    DataReply(int num): Packet('A'), seqNum(num) {};
    char* serialize() override;
};

class CloseConnection : public Packet
{
private:
    int seqNum;
public:
    CloseConnection(int num): Packet('C'), seqNum(num) {};
    char* serialize() override;

};


#endif //RELIABLEPROTOCOL_PACKET_H
