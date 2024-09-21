//
// Created by tiferka on 16.08.24.
//
#include "AcceptedStream.h"

std::string AcceptedStream::process(std::string &string) {
    std::cout << "String after processing: \"" << string << "\"" << std::endl;
    int sum = 0;
    for (char ch: string) {
        if (std::isdigit(ch)) sum += ch - '0';
    }
    string.clear();
    return std::to_string(sum);
}
