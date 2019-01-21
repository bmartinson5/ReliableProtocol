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

#include "Packet.h"
using namespace std;


int threeWayHandshake(int ip, int port, string fileName)
{
//    cout << endl << fileName << endl;
    //create file request packet
    Connection connectionPacket(fileName.length(), fileName);
    char *packet = connectionPacket.serialize();
    //send request to port

    //wait for reply with fileSize
    //create connection Reply ACK Packet
    //send confirmation

}

int receiveData()
{

}

int main(int argc, char *argv[]) {

    if(argc != 4) cout << "\nInvalid Arguments";

    int sockfd, portno, n;



    threeWayHandshake(atoi(argv[1]), atoi(argv[2]), {argv[3]});

//    Connection connection(5, "helloWOrld");
//    char *arr = connection.serialize();
//    for(int i = 0; arr[i] != '\0'; ++i)
//    {
//        cout << arr[i];
//    }



    return 0;
}




