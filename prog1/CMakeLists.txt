cmake_minimum_required(VERSION 3.22.1)
project(infotecs)

set(CMAKE_CXX_STANDARD 20)

add_library(AcceptedStream FirstProgramme/Streams/AcceptedStream.cpp FirstProgramme/Streams/AcceptedStream.h
        FirstProgramme/Socket/Socket.cpp
        FirstProgramme/Socket/Socket.h)
add_library(ProcessStream FirstProgramme/Streams/ProcessStream.cpp FirstProgramme/Streams/ProcessStream.h)
add_library(FirstProgramme FirstProgramme/FirstProgramme.cpp FirstProgramme/FirstProgramme.h)

add_library(Socket FirstProgramme/Socket/Socket.cpp FirstProgramme/Socket/Socket.h)

target_link_libraries(FirstProgramme AcceptedStream ProcessStream Socket)


add_executable(infotecs main.cpp)

target_link_libraries(infotecs FirstProgramme)

