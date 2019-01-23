CXX=g++
CXXFLAGS= -std=c++11

client: Client.cpp Packet.cpp SocketAction.cpp
	$(CXX) $(CXXFLAGS) Client.cpp Packet.cpp SocketAction.cpp -o client

server: Server.cpp Packet.cpp SocketAction.cpp
	$(CXX) $(CXXFLAGS) server.cpp Packet.cpp SocketAction.cpp -o server

all: 
	make client
	make server

run:	client
	./client 127.0.0.1 1080 filename

run2:	server
	./server 127.0.0.1 1080
