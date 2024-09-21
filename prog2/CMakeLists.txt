cmake_minimum_required(VERSION 3.22.1)
project(infotecsProg2)

set(CMAKE_CXX_STANDARD 20)

add_library(DefaultAnalizer SecondProgramme/Analyzer/DefaultAnalizer.cpp SecondProgramme/Analyzer/DefaultAnalizer.h)

add_library(SecondProgramme SecondProgramme/SecondProgramme.cpp SecondProgramme/SecondProgramme.h
        SecondProgramme/Connector.h)

add_library(Socket SecondProgramme/Socket/Socket.cpp SecondProgramme/Socket/Socket.h)

target_link_libraries(SecondProgramme DefaultAnalizer Socket)

add_executable(infotecsProg2 main.cpp)

target_link_libraries(infotecsProg2 SecondProgramme)