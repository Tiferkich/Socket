//
// Created by tiferka on 16.08.24.
//


#include "DefaultAnalizer.h"

std::string DefaultAnalizer::analyze(const std::string &data) {
    if (data[0] == EXIT) return "EXIT";
    int dataDigit;
    try {
        dataDigit = std::stoi(data);
    } catch (std::exception &e) {
        return std::string{"Data is incorrect"};
    }
    if (data.size() < 2 || dataDigit % 32 != 0) return std::string{"Data is incorrect"};
    return std::string{"Data is correct"};
}
