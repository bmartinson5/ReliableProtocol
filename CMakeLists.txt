cmake_minimum_required(VERSION 3.12)
project(ReliableProtocol)

set(CMAKE_CXX_STANDARD 14)

add_executable(ReliableProtocol main.cpp Packet.cpp Packet.h Client.cpp Client.h Server.cpp Server.h)