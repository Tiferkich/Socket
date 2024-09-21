//
// Created by tiferka on 16.08.24.
//

#ifndef INFOTECS_STREAM_H
#define INFOTECS_STREAM_H

#include <string>
#include <iostream>


///Интерфейс потока, чтобы расширять нашу программу
class Stream {
public:
    virtual std::string process(std::string &string) = 0;

    virtual ~Stream() = default;
};

#endif //INFOTECS_STREAM_H
